// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: tainted-mult-int32.json
//
// Знаковое значение вводится с помощью функции scanf.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое может привести к переполнению снизу.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct inner_struct_type {
  int inner_field1;
  int inner_field2;
  int inner_field3;
};

struct struct_type {
  int field1;
  struct inner_struct_type *field2;
  int field3;
};

int callee(struct struct_type *struct_param) {
  if (struct_param->field2->inner_field2 > 10)
    return 1;
  else
    return 0;
}

void func(void) {
  int32_t data = 1;
  int32_t result;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -16;
  inner_struct_var.inner_field2 = 1;
  inner_struct_var.inner_field3 = 57;

  struct struct_type struct_var;
  struct_var.field1 = -7;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 30;

  scanf("%d", &data);

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  result = data * 2;
}

// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint64.json
//
// Беззнаковое значение задается с помощью константы ULLONG_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
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
  uint64_t data = 0;
  uint64_t result;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -93;
  inner_struct_var.inner_field2 = 7;
  inner_struct_var.inner_field3 = 80;

  struct struct_type struct_var;
  struct_var.field1 = -56;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 72;

  data = ULLONG_MAX;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  result = data + 1;
}

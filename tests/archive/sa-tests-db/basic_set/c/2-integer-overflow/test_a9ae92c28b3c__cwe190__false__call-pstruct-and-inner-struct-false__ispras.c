// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

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
  int number = 0;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -91;
  inner_struct_var.inner_field2 = 1;
  inner_struct_var.inner_field3 = 21;

  struct struct_type struct_var;
  struct_var.field1 = -78;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 83;

  scanf("%d", &number);

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  global = (int *)malloc(number * sizeof(int));

  free(global);
}

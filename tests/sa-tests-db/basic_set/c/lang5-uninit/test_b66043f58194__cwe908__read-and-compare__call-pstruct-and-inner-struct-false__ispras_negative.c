// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

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

int *func(void) {

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -5;
  inner_struct_var.inner_field2 = 4;
  inner_struct_var.inner_field3 = 77;

  struct struct_type struct_var;
  struct_var.field1 = -41;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 29;

  int *x = malloc(sizeof(int));

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  if (x != NULL && *x < 0) {
    *x = 0;
  }

  return x;
}

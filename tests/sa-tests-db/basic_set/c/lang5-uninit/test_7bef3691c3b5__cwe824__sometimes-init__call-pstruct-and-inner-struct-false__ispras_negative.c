// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: sometimes-init.json
//
// Запись значения по указателю, инициализированному не на всех путях.
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

void func(int *input_ptr, int cond_param) {

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -13;
  inner_struct_var.inner_field2 = 2;
  inner_struct_var.inner_field3 = 81;

  struct struct_type struct_var;
  struct_var.field1 = 7;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 72;

  int *x;
  if (cond_param > 0) {
    x = input_ptr;
  }

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  *x = -34;
}

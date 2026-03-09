// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdlib.h>

int *null_func(int null_func_arg) { return NULL; }

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
  int *pointer, other, dummy;
  pointer = &dummy;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = 9;
  inner_struct_var.inner_field2 = 1;
  inner_struct_var.inner_field3 = 11;

  struct struct_type struct_var;
  struct_var.field1 = -47;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 64;

  pointer = null_func(34);

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  *pointer = 0;
}

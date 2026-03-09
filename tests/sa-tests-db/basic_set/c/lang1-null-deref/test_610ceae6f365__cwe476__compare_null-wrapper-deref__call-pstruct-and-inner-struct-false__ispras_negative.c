// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

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

int func(int *param) {
  int template_flag = 0;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -42;
  inner_struct_var.inner_field2 = 1;
  inner_struct_var.inner_field3 = 52;

  struct struct_type struct_var;
  struct_var.field1 = -81;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 72;

  if (param == NULL) {
    template_flag = 54;
  }

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  wrapper(param);

  return 0;
}

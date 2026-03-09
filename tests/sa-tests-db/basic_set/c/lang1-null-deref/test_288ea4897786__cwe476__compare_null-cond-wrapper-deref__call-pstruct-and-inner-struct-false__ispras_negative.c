// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-cond-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр больше нуля.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

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
  inner_struct_var.inner_field1 = -6;
  inner_struct_var.inner_field2 = 9;
  inner_struct_var.inner_field3 = 94;

  struct struct_type struct_var;
  struct_var.field1 = -72;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 38;

  if (param == NULL) {
    template_flag = 20;
  }

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  wrapper(param, 18);

  return 0;
}

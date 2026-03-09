// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
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

void func(void) {
  int divident = 68, divisor = 8, result;
  int var_a = 108;
  int var_b = 114;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -98;
  inner_struct_var.inner_field2 = 6;
  inner_struct_var.inner_field3 = 25;

  struct struct_type struct_var;
  struct_var.field1 = -82;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 39;

  divisor = var_a - var_b;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  result = divident / divisor;
}

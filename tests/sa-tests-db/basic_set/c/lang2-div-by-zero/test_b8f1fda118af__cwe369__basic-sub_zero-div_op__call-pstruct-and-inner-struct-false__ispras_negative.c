// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
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
  int divident = 16, divisor = 7, result;
  int var_a = 115;
  int var_b = 115;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -86;
  inner_struct_var.inner_field2 = 5;
  inner_struct_var.inner_field3 = 77;

  struct struct_type struct_var;
  struct_var.field1 = -41;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 22;

  divisor = var_a - var_b;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  result = divident / divisor;
}

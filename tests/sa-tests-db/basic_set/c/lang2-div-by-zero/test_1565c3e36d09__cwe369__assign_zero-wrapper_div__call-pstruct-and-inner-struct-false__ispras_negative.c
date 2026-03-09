// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1045 / wrapper_par; }

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
  int divident = 38, divisor = 10, result;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -42;
  inner_struct_var.inner_field2 = 3;
  inner_struct_var.inner_field3 = 61;

  struct struct_type struct_var;
  struct_var.field1 = -19;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 63;

  divisor = 0;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  result = wrapper(divisor);
}

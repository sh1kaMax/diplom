// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1819 / (wrapper_par - 17); }

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
  int divident = 42, divisor = 3, result;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -57;
  inner_struct_var.inner_field2 = 3;
  inner_struct_var.inner_field3 = 100;

  struct struct_type struct_var;
  struct_var.field1 = -47;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 94;

  divisor = 17;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  result = wrapper(divisor);
}

// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-global.json
//
// Чтение значения неинициализированной глобальной переменной для использования
// при вычислении выражения.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdlib.h>

int x;

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

int func(void) {
  int result = 0;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -53;
  inner_struct_var.inner_field2 = 7;
  inner_struct_var.inner_field3 = 64;

  struct struct_type struct_var;
  struct_var.field1 = -94;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 47;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  result = x + 1;

  return result;
}

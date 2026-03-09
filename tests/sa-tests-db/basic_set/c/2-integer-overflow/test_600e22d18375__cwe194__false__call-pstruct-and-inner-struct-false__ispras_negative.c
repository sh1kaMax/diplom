// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

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
  char string[53];
  short number = 52;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -17;
  inner_struct_var.inner_field2 = 5;
  inner_struct_var.inner_field3 = 80;

  struct struct_type struct_var;
  struct_var.field1 = -57;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 42;

  scanf("%hd", &number);
  if (number > 52)
    number = 52;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[52] = '\0';
}

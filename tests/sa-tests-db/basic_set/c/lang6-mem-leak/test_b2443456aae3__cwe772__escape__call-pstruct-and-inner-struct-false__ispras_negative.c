// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

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

void func(const char *path) {
  FILE *f = NULL;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -83;
  inner_struct_var.inner_field2 = 10;
  inner_struct_var.inner_field3 = 86;

  struct struct_type struct_var;
  struct_var.field1 = -88;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 62;

  f = fopen(path, "r");

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  gf = f;
}

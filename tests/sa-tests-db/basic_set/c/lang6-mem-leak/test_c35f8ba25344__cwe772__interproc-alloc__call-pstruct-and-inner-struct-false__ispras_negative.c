// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-alloc.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор возвращается из пользовательской функции.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdio.h>
#include <stdlib.h>

FILE *my_fopen(const char *my_path) {
  if (my_path != NULL) {
    return fopen(my_path, "r");
  } else {
    return NULL;
  }
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

void func(const char *path) {
  FILE *f = NULL;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -95;
  inner_struct_var.inner_field2 = 9;
  inner_struct_var.inner_field3 = 51;

  struct struct_type struct_var;
  struct_var.field1 = -62;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 80;

  f = my_fopen(path);

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  if (f != NULL) {
    fclose(f);
  }
}

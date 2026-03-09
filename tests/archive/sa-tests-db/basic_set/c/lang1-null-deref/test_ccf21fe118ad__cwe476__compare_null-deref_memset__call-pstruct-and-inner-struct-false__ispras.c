// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

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
  int template_flag;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -44;
  inner_struct_var.inner_field2 = 4;
  inner_struct_var.inner_field3 = 13;

  struct struct_type struct_var;
  struct_var.field1 = -20;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 93;

  if (param == NULL) {
    template_flag = 69;
  }

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  memset(param, 0, sizeof(int));
  use_mem_to_keep_memset(param);

  return 0;
}

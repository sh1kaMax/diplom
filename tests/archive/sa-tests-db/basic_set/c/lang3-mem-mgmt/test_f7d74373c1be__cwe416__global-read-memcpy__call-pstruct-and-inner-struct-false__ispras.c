// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-read-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память читается с использованием стандартной функции memcpy.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdlib.h>
#include <string.h>

int *pointer = NULL;

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
  int freed_flag = 0;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -11;
  inner_struct_var.inner_field2 = 3;
  inner_struct_var.inner_field3 = 96;

  struct struct_type struct_var;
  struct_var.field1 = -75;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 87;

  pointer = malloc(sizeof(int));
  *pointer = *param;
  free(pointer);
  freed_flag = 1;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  if (pointer) {
    memcpy(param, pointer, sizeof(int));
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}

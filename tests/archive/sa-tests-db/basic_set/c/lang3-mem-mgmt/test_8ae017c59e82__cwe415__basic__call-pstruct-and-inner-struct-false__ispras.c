// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
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
  int *pointer = NULL;
  int freed_flag = 0;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -23;
  inner_struct_var.inner_field2 = 3;
  inner_struct_var.inner_field3 = 65;

  struct struct_type struct_var;
  struct_var.field1 = -64;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 85;

  pointer = (int *)malloc(27 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  free(pointer);
}

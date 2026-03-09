// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
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
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -30;
  inner_struct_var.inner_field2 = 2;
  inner_struct_var.inner_field3 = 72;

  struct struct_type struct_var;
  struct_var.field1 = -41;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 74;

  pointer1 = (int *)malloc(30 * sizeof(int));
  pointer2 = (int *)malloc(30 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  free(pointer1);
  free(pointer2);
  pointer1 = NULL;

  free(pointer1);
}

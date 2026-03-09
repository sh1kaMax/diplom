// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdio.h>
#include <stdlib.h>

int store;

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
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -97;
  inner_struct_var.inner_field2 = 3;
  inner_struct_var.inner_field3 = 26;

  struct struct_type struct_var;
  struct_var.field1 = -96;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 56;

  scanf("%d", &index);

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  store = array[index];
}

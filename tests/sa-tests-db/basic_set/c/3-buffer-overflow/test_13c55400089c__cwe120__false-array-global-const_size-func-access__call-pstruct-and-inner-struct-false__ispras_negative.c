// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции.
// Индекс является константой.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdlib.h>

int buffer[21];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

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
  int result = 0;
  unsigned int index = 0;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -40;
  inner_struct_var.inner_field2 = 7;
  inner_struct_var.inner_field3 = 14;

  struct struct_type struct_var;
  struct_var.field1 = -63;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 29;

  index = 21;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  result = get_buffer_elem(index);

  return;
}

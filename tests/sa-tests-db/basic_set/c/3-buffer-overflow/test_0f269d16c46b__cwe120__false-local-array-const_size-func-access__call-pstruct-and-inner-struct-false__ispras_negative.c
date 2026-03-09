// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-local-array-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. Индекс является константой.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[36];
  int cur_index = 0;
  for (; cur_index < 36; cur_index++)
    buffer[cur_index] = 50;
  return buffer[elem_index];
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

void func(void) {
  int result = 0;
  unsigned int index = 0;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = -27;
  inner_struct_var.inner_field2 = 5;
  inner_struct_var.inner_field3 = 97;

  struct struct_type struct_var;
  struct_var.field1 = -26;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 23;

  index = 36;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  result = get_buffer_elem(index);

  return;
}

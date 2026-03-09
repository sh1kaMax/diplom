// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-wrapper-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Указатель на буфер получен с помощью вызова функции, которая всегда
// возвращает буфер. Доступ к буферу осуществляется через указатель (с помощью
// операции индексации). Индекс является константой.
//
// Поточный вариант: call-pstruct-and-inner-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения поля вложенной структуры; структура
// передаётся по указателю в вызываемую функцию через её аргумент; возвращаемое
// из вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// успешна и выполнение не достигает стока.

#include <stdlib.h>

int buffer[20];
int *get_buffer_func() { return buffer; }

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
  int *buf_ptr;

  struct inner_struct_type inner_struct_var;
  inner_struct_var.inner_field1 = 2;
  inner_struct_var.inner_field2 = 9;
  inner_struct_var.inner_field3 = 26;

  struct struct_type struct_var;
  struct_var.field1 = 9;
  struct_var.field2 = &inner_struct_var;
  struct_var.field3 = 53;

  index = 20;

  if (callee(&struct_var) == 0) {
    exit(0);
  }

  buf_ptr = get_buffer_func();
  result = buf_ptr[index];

  return;
}

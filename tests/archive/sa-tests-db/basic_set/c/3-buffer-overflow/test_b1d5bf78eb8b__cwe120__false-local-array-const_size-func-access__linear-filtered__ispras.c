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
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[27];
  int cur_index = 0;
  for (; cur_index < 27; cur_index++)
    buffer[cur_index] = 48;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  index = 27;

  index = 27 - 1;

  result = get_buffer_elem(index);

  return;
}

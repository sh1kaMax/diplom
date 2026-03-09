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
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[39];
  int cur_index = 0;
  for (; cur_index < 39; cur_index++)
    buffer[cur_index] = 72;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  result = get_buffer_elem(index);

  index = 39;

  return;
}

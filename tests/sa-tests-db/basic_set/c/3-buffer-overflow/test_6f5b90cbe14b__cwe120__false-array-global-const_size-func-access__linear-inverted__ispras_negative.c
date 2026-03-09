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
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <stdlib.h>

int buffer[32];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  result = get_buffer_elem(index);

  index = 32;

  return;
}

// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-local-array-const_size-func-safe-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. В функции доступа есть проверка на границы индекса. Индекс
// является константой.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[21];
  int cur_index = 0;
  for (; cur_index < 21; cur_index++)
    buffer[cur_index] = 58;
  if (elem_index >= 21)
    return -1;
  return buffer[elem_index];
}

void func(void) {
  int iter_var;

  int result = 0;
  unsigned int index = 0;

  for (iter_var = 3; iter_var < 25; iter_var++) {
    index = 21;

    result = get_buffer_elem(index);
  }

  return;
}

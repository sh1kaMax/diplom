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
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[33];
  int cur_index = 0;
  for (; cur_index < 33; cur_index++)
    buffer[cur_index] = 27;
  if (elem_index >= 33)
    return -1;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var;

  index = 33;

  var = 0;

  do {
    var++;
  } while (var < 16);

  result = get_buffer_elem(index);

  return;
}

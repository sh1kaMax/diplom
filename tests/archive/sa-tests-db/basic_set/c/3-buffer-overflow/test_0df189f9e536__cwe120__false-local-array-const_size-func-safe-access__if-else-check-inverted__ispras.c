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
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[23];
  int cur_index = 0;
  for (; cur_index < 23; cur_index++)
    buffer[cur_index] = 86;
  if (elem_index >= 23)
    return -1;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  index = 23;

  if (!(index >= 23)) {
    exit(0);
  } else {
    result = get_buffer_elem(index);
  }

  return;
}

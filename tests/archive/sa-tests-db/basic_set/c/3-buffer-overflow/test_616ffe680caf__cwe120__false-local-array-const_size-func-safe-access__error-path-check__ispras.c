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
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[40];
  int cur_index = 0;
  for (; cur_index < 40; cur_index++)
    buffer[cur_index] = 25;
  if (elem_index >= 40)
    return -1;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  index = 40;

  if (index >= 40)
    goto error_label;

  index = 40 - 1;

  exit(0);

error_label:
  result = get_buffer_elem(index);

  return;
}

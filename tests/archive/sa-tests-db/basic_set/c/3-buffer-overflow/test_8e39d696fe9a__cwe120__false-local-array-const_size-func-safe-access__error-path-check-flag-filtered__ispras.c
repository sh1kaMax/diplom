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
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[30];
  int cur_index = 0;
  for (; cur_index < 30; cur_index++)
    buffer[cur_index] = 13;
  if (elem_index >= 30)
    return -1;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int flag = 0;

  index = 30;

  if (index >= 30)
    flag = 1;

  if (flag != 0) {

    index = 30 - 1;

    goto error_label;
  }

  exit(0);

error_label:
  result = get_buffer_elem(index);

  return;
}

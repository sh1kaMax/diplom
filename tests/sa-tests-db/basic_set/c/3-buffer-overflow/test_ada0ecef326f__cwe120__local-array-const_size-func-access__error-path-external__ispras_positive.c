// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: local-array-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. Индекс является константой.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int get_buffer_elem(int elem_index) {
  int buffer[33];
  int cur_index = 0;
  for (; cur_index < 33; cur_index++)
    buffer[cur_index] = 75;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  index = 33;

  if (external_func())
    goto error_label;

  index = 33 - 1;

  exit(0);

error_label:
  result = get_buffer_elem(index); // FLAW

  return;
}

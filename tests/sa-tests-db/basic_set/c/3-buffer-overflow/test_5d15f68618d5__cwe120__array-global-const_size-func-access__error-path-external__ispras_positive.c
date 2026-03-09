// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-global-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции.
// Индекс является константой.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int buffer[30];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  index = 30;

  if (external_func())
    goto error_label;

  index = 30 - 1;

  exit(0);

error_label:
  result = get_buffer_elem(index); // FLAW

  return;
}

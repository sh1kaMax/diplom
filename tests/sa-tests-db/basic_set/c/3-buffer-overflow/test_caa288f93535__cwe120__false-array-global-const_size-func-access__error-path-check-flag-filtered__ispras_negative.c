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
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

int buffer[35];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int flag = 0;

  index = 35;

  if (index >= 35)
    flag = 1;

  if (flag != 0) {

    index = 35 - 1;

    goto error_label;
  }

  exit(0);

error_label:
  result = get_buffer_elem(index);

  return;
}

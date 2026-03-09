// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-func-no-access-if.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, если 2й параметр
// функции больше нуля. 2й параметр меньше нуля, поэтому доступа нет. Индекс
// является константой.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

int buffer[30];
int get_buffer_elem(int elem_index, int temp_flag) {
  if (temp_flag > 0)
    return buffer[elem_index];
  return 0;
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
  result = get_buffer_elem(index, -1);

  return;
}

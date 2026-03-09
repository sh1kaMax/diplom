// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-local-array-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. Индекс является константой.
//
// Поточный вариант: switch-default-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[28];
  int cur_index = 0;
  for (; cur_index < 28; cur_index++)
    buffer[cur_index] = 13;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var;

  index = 28;

  var = 0;

  switch (var) {
  default:
    result = get_buffer_elem(index);
    break;
  case 0:
    exit(0);
    break;
  }

  return;
}

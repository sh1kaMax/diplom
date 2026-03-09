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
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[38];
  int cur_index = 0;
  for (; cur_index < 38; cur_index++)
    buffer[cur_index] = 30;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var;

  index = 38;

  var = (index >= 38 ? 0 : 1);

  if (var) {
    result = get_buffer_elem(index);
  }

  return;
}

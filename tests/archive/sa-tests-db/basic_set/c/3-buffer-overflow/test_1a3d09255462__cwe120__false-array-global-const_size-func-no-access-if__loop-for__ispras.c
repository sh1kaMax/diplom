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
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int buffer[38];
int get_buffer_elem(int elem_index, int temp_flag) {
  if (temp_flag > 0)
    return buffer[elem_index];
  return 0;
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var;

  index = 38;

  var = 0;

  for (var = 0; var < 17; var++)
    ;

  result = get_buffer_elem(index, -1);

  return;
}

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
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

int buffer[35];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  index = 35;

  if (!(index >= 35)) {
    exit(0);
  } else {
    result = get_buffer_elem(index); // FLAW
  }

  return;
}

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
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int buffer[26];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var;

  index = 26;

  var = 0;

  do {
    var++;
  } while (var < 18);

  result = get_buffer_elem(index); // FLAW

  return;
}

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
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[38];
  int cur_index = 0;
  for (; cur_index < 38; cur_index++)
    buffer[cur_index] = 84;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var, var2;

  index = 38;

  for (var = 0; var < 20; var++) {
    for (var2 = var; var2 < 10; var2++) {
      result = get_buffer_elem(index); // FLAW
    }
  }

  return;
}

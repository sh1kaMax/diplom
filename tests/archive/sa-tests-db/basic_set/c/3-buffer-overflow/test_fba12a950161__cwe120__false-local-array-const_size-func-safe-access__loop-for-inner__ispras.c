// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-local-array-const_size-func-safe-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. В функции доступа есть проверка на границы индекса. Индекс
// является константой.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[28];
  int cur_index = 0;
  for (; cur_index < 28; cur_index++)
    buffer[cur_index] = 97;
  if (elem_index >= 28)
    return -1;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var, var2;

  index = 28;

  for (var = 0; var < 14; var++) {
    for (var2 = var; var2 < 20; var2++) {
      result = get_buffer_elem(index);
    }
  }

  return;
}

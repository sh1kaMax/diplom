// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: local-array-const_size-func-access-with-check.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. В функции доступа есть проверка на границы индекса, но она
// недостаточная Индекс является константой. Нормально, если анализатор выдаст
// предупреждение только внутри функции get_buffer_elem, т.к. кода этой функции
// достаточно, чтобы сообщить о проблеме, нет смысла выдавать выше.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[38];
  int cur_index = 0;
  for (; cur_index < 38; cur_index++)
    buffer[cur_index] = 55;
  if (elem_index > 38)
    return -1;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var;

  index = 38;

  var = 0;

  do {
    var++;
  } while (var < 17);

  result = get_buffer_elem(index); // FLAW

  return;
}

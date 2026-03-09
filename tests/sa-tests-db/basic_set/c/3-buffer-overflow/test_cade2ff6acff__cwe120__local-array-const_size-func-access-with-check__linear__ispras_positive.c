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
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[20];
  int cur_index = 0;
  for (; cur_index < 20; cur_index++)
    buffer[cur_index] = 83;
  if (elem_index > 20)
    return -1;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  index = 20;

  result = get_buffer_elem(index); // FLAW

  return;
}

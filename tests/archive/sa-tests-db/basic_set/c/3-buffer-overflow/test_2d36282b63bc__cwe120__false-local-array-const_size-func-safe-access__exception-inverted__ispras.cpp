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
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[27];
  int cur_index = 0;
  for (; cur_index < 27; cur_index++)
    buffer[cur_index] = 14;
  if (elem_index >= 27)
    return -1;
  return buffer[elem_index];
}

class ExceptionClass {};

void func(void) {
  int result = 0;
  unsigned int index = 0;

  try {
    result = get_buffer_elem(index);
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    index = 27;
  }

  return;
}

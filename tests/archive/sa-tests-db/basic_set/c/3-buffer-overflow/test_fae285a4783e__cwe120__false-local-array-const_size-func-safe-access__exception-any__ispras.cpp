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
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[23];
  int cur_index = 0;
  for (; cur_index < 23; cur_index++)
    buffer[cur_index] = 39;
  if (elem_index >= 23)
    return -1;
  return buffer[elem_index];
}

class ExceptionClass {};

void func(void) {
  int result = 0;
  unsigned int index = 0;

  try {
    index = 23;
    throw ExceptionClass();
  } catch (...) {
    result = get_buffer_elem(index);
  }

  return;
}

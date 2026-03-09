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
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[39];
  int cur_index = 0;
  for (; cur_index < 39; cur_index++)
    buffer[cur_index] = 58;
  return buffer[elem_index];
}

class ExceptionClass {};

void func(void) {
  int result = 0;
  unsigned int index = 0;

  try {
    index = 39;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = get_buffer_elem(index); // FLAW
  }

  return;
}

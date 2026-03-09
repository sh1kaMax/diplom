// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции.
// Индекс является константой.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

int buffer[25];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

class ExceptionClass {};

void func(void) {
  int result = 0;
  unsigned int index = 0;

  try {
    result = get_buffer_elem(index);
    throw ExceptionClass();
    index = 25;
  } catch (const ExceptionClass &excpt) {
  }

  return;
}

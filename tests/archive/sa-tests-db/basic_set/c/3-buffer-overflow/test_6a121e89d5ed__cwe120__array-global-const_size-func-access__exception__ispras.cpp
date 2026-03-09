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
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int buffer[20];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

class ExceptionClass {};

void func(void) {
  int result = 0;
  unsigned int index = 0;

  try {
    index = 20;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = get_buffer_elem(index); // FLAW
  }

  return;
}

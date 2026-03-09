// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-const_size-func-access-with-index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которую передаётся
// массив по указателю. Индекс является константой.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int get_buffer_elem(int *buf_ptr_par, int buf_index_par) {
  return buf_ptr_par[buf_index_par];
}

class ExceptionClass {};

void func(void) {
  int buffer[17];
  int result = 0;
  unsigned int index = 0;

  try {
    index = 17;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = get_buffer_elem(buffer, index); // FLAW
  }

  return;
}

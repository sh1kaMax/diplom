// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-wrapper-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Указатель на буфер получен с помощью вызова функции, которая всегда
// возвращает буфер. Доступ к буферу осуществляется через указатель (с помощью
// операции индексации). Индекс является константой.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

int buffer[34];
int *get_buffer_func() { return buffer; }

class ExceptionClass {};

void func(void) {
  int result = 0;
  unsigned int index = 0;
  int *buf_ptr;

  try {
    buf_ptr = get_buffer_func();
    result = buf_ptr[index];
    throw ExceptionClass();
    index = 34;
  } catch (const ExceptionClass &excpt) {
  }

  return;
}

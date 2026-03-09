// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int buffer[33];

class ExceptionClass {};

void func(void) {
  int result = 0;
  unsigned int index = 0;

  try {
    result = buffer[index];
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    index = 33;
  }

  return;
}

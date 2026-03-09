// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-dynamic-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int result = 0;

class ExceptionClass {};

void func(void) {
  int *buffer = (int *)malloc(33 * sizeof(int));
  unsigned int index = 0;

  try {
    index = 33;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = buffer[index]; // FLAW
  }

  free(buffer);
  return;
}

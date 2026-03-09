// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-dynamic-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

int result = 0;

class ExceptionClass {};

void func(void) {
  int *buffer = (int *)malloc(28 * sizeof(int));
  unsigned int index = 0;

  try {
    result = buffer[index];
    throw ExceptionClass();
    index = 28;
  } catch (const ExceptionClass &excpt) {
  }

  free(buffer);
  return;
}

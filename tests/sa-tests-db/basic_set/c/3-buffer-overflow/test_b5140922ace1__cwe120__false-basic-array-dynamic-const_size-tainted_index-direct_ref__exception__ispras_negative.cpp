// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-dynamic-const_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdio.h>
#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int *buffer = (int *)malloc(35 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  try {
    result = buffer[index];
    throw ExceptionClass();
    scanf("%u", &index);
  } catch (const ExceptionClass &excpt) {
  }

  free(buffer);
  return;
}

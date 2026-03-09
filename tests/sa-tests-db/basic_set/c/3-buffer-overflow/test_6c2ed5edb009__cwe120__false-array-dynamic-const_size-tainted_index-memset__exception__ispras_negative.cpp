// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-dynamic-const_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

class ExceptionClass {};

void func(void) {
  int *buffer = (int *)malloc(30 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  try {
    memset(buffer, 0, index * sizeof(int));
    use_mem_to_keep_memset(buffer);
    throw ExceptionClass();
    scanf("%u", &index);
  } catch (const ExceptionClass &excpt) {
  }

  free(buffer);
  return;
}

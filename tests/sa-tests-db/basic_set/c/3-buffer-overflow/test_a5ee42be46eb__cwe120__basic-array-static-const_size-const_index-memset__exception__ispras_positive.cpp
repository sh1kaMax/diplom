// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-static-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>
#include <string.h>

int result = 0;
int buffer[25];
void use_mem_to_keep_memset(int *);

class ExceptionClass {};

void func(void) {
  unsigned int index = 0;

  try {
    index = 25 + 1;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    memset(buffer, 0, index * sizeof(int)); // FLAW
    use_mem_to_keep_memset(buffer);
  }

  return;
}

// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-static-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>
#include <string.h>

int result = 0;
int buffer[31];
void use_mem_to_keep_memset(int *);

class ExceptionClass {};

void func(void) {
  unsigned int index = 0;

  try {
    memset(buffer, 0, index * sizeof(int));
    use_mem_to_keep_memset(buffer);
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    index = 31 + 1;
  }

  return;
}

// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-auto-const_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdio.h>

class ExceptionClass {};

void func(void) {
  int buffer[39];
  int result = 0;
  unsigned int index = 0;

  try {
    result = buffer[index];
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    scanf("%u", &index);
  }

  return;
}

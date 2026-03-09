// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 9; }

class ExceptionClass {};

void func(void) {
  int buffer[32];
  unsigned int index = 0;

  try {
    index = index_change_func(index);
    result = buffer[index];
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    index = 32;
  }

  return;
}

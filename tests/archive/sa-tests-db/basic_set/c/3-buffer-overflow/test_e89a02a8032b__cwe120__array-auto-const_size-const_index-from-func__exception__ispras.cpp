// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 10; }

class ExceptionClass {};

void func(void) {
  int buffer[20];
  unsigned int index = 0;

  try {
    index = 20;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    index = index_change_func(index);
    result = buffer[index]; // FLAW
  }

  return;
}

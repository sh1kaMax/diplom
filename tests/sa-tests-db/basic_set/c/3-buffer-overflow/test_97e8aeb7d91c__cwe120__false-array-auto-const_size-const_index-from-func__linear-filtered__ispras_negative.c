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
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 9; }

void func(void) {
  int buffer[25];
  unsigned int index = 0;

  index = 25;

  index = 25 - 1 - 9;

  index = index_change_func(index);
  result = buffer[index];

  return;
}

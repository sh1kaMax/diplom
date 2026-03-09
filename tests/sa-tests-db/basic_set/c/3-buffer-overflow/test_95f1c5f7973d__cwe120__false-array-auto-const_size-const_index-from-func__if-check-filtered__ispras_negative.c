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
// Поточный вариант: if-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае истинности проверки.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 1; }

void func(void) {
  int buffer[34];
  unsigned int index = 0;

  index = 34;

  if (index >= 34) {
    index = 34 - 1 - 1;
  }

  index = index_change_func(index);
  result = buffer[index];

  return;
}

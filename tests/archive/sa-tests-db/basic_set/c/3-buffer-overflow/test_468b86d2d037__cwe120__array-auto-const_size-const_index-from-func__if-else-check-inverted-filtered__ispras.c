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
// Поточный вариант: if-else-check-inverted-filtered.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 6; }

void func(void) {
  int buffer[26];
  unsigned int index = 0;

  index = 26;

  if (!(index >= 26)) {
    index = 26 - 1 - 6;
  } else {
    index = index_change_func(index);
    result = buffer[index]; // FLAW
  }

  return;
}

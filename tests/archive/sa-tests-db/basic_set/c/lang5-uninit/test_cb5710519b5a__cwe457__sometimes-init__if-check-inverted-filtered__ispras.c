// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: sometimes-init.json
//
// Чтение значения переменной, инициализированной не на всех путях.
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки.

#include <stdlib.h>

int func(int cond_param) {
  int result = 0;

  int x;
  if (cond_param > 0) {
    x = cond_param;
  }

  if (!(1)) {
    x = 38;
  }

  result = x + 1; // FLAW

  return result;
}

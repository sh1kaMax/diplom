// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: sometimes-init.json
//
// Чтение значения переменной, инициализированной не на всех путях.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int func(int cond_param) {
  int result = 0;

  int flag = 0;

  int x;
  if (cond_param > 0) {
    x = cond_param;
  }

  if (1)
    flag = 1;

  if (flag != 0)
    goto error_label;

  x = 24;

  exit(0);

error_label:
  result = x + 1; // FLAW

  return result;
}

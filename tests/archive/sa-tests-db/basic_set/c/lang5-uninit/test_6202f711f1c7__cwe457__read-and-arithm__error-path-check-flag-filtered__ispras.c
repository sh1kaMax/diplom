// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-arithm.json
//
// Чтение значения неинициализированной переменной для использования при
// вычислении выражения.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

int func(void) {
  int result = 0;

  int flag = 0;

  int x;

  if (1)
    flag = 1;

  if (flag != 0) {

    x = -2;

    goto error_label;
  }

  exit(0);

error_label:
  result = x + 1;

  return result;
}

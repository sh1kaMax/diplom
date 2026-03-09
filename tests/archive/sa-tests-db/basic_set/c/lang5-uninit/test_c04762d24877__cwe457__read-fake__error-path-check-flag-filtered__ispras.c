// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-fake.json
//
// Отсутствие чтения значения неинициализированной переменной, несмотря не ее
// использование при вычислении выражения.
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

    x = -81;

    goto error_label;
  }

  exit(0);

error_label:
  result = sizeof x + 1;

  return result;
}

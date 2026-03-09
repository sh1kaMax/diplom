// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-global.json
//
// Чтение значения неинициализированной глобальной переменной для использования
// при вычислении выражения.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int x;

int func(void) {
  int result = 0;

  int flag = 0;

  if (1)
    flag = 1;

  if (flag != 0)
    goto error_label;

  x = 6;

  exit(0);

error_label:
  result = x + 1;

  return result;
}

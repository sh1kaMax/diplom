// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-arithm.json
//
// Чтение значения неинициализированной переменной для использования при
// вычислении выражения.
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

int func(void) {
  int result = 0;

  int x;

  if (1)
    goto error_label;

  x = 22;

  exit(0);

error_label:
  result = x + 1; // FLAW

  return result;
}

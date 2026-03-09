// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-compare.json
//
// Чтение значения неинициализированной переменной для использования в условном
// операторе.
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>

int func(void) {
  int result = 0;

  int x;

  if (1) {

    x = 76;

    goto error_label;
  }

  exit(0);

error_label:
  if (x > 0) {
    result = 1;
  }

  return result;
}

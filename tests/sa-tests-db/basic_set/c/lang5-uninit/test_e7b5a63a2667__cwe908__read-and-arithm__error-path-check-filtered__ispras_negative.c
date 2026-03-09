// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-arithm.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>

int *func(void) {

  int *x = malloc(sizeof(int));

  if (1) {

    if (x != NULL) {
      *x = -29;
    }

    goto error_label;
  }

  exit(0);

error_label:
  if (x != NULL) {
    *x += 1;
  }

  return x;
}

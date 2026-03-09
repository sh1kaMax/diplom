// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

int *func(void) {

  int *x = malloc(sizeof(int));

  if (1)
    goto error_label;

  if (x != NULL) {
    *x = 93;
  }

  exit(0);

error_label:
  if (x != NULL && *x < 0) { // FLAW
    *x = 0;
  }

  return x;
}

// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-return.json
//
// Возврат значения неинициализированного указателя из функции.
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

int *func(void) {
  int *result = NULL;

  int *x;

  if (1)
    goto error_label;

  x = malloc(sizeof(int));

  exit(0);

error_label:
  result = x; // FLAW

  return result;
}

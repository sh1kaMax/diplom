// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-fake.json
//
// Отсутствие чтения значения из неинициализированной памяти, несмотря не ее
// использование при вычислении выражения.
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
    *x = 56;
  }

  exit(0);

error_label:
  if (x != NULL) {
    *x = sizeof *x;
  }

  return x;
}

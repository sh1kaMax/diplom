// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-fake.json
//
// Отсутствие чтения значения из неинициализированной памяти, несмотря не ее
// использование при вычислении выражения.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int *func(void) {

  int *x = malloc(sizeof(int));

  if (external_func())
    goto error_label;

  if (x != NULL) {
    *x = -85;
  }

  exit(0);

error_label:
  if (x != NULL) {
    *x = sizeof *x;
  }

  return x;
}

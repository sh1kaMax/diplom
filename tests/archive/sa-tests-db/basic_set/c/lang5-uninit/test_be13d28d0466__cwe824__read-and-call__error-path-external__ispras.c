// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-call.json
//
// Передача значения неинициализированного указателя во внешнюю функцию.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int model_external_func(int *external_param);

int func(void) {
  int result = 0;

  int *x;

  if (external_func())
    goto error_label;

  x = malloc(sizeof(int));

  exit(0);

error_label:
  result = model_external_func(x); // FLAW

  return result;
}

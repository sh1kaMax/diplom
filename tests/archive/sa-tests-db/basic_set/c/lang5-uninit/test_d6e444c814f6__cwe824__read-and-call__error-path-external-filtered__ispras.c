// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-call.json
//
// Передача значения неинициализированного указателя во внешнюю функцию.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>

int external_func(void);

int model_external_func(int *external_param);

int func(void) {
  int result = 0;

  int *x;

  if (external_func()) {

    x = malloc(sizeof(int));

    goto error_label;
  }

  exit(0);

error_label:
  result = model_external_func(x);

  return result;
}

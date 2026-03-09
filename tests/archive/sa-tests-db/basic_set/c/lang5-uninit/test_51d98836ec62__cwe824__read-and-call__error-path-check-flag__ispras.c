// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-call.json
//
// Передача значения неинициализированного указателя во внешнюю функцию.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int model_external_func(int *external_param);

int func(void) {
  int result = 0;

  int flag = 0;

  int *x;

  if (1)
    flag = 1;

  if (flag != 0)
    goto error_label;

  x = malloc(sizeof(int));

  exit(0);

error_label:
  result = model_external_func(x); // FLAW

  return result;
}

// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-call.json
//
// Передача значения неинициализированного указателя во внешнюю функцию.
//
// Поточный вариант: if-check.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, выход в случае истинности проверки.

#include <stdlib.h>

int model_external_func(int *external_param);

int func(void) {
  int result = 0;

  int *x;

  if (1) {
    exit(0);
  }

  result = model_external_func(x);

  return result;
}

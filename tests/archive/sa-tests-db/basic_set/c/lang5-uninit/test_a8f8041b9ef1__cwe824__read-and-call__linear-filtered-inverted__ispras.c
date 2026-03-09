// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-call.json
//
// Передача значения неинициализированного указателя во внешнюю функцию.
//
// Поточный вариант: linear-filtered-inverted.c
// Прямолинейный участок кода от источника до стока с фильтрацией после стока.

#include <stdlib.h>

int model_external_func(int *external_param);

int func(void) {
  int result = 0;

  int *x;

  result = model_external_func(x); // FLAW

  x = malloc(sizeof(int));

  return result;
}

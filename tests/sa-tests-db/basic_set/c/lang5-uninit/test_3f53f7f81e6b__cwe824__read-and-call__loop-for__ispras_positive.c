// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-call.json
//
// Передача значения неинициализированного указателя во внешнюю функцию.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int model_external_func(int *external_param);

int func(void) {
  int result = 0;

  int var;

  int *x;

  var = 0;

  for (var = 0; var < 15; var++)
    ;

  result = model_external_func(x); // FLAW

  return result;
}

// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-call.json
//
// Передача значения неинициализированного указателя во внешнюю функцию.
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int model_external_func(int *external_param);

int func(void) {
  int result = 0;

  int var;

  int *x;

  var = 0;

  while (var < 19)
    var++;

  result = model_external_func(x); // FLAW

  return result;
}

// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-call.json
//
// Передача значения неинициализированного указателя во внешнюю функцию.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int model_external_func(int *external_param);

int func(void) {
  int result = 0;

  int var;

  int *x;

  var = 0;

  do {
    var++;
  } while (var < 17);

  result = model_external_func(x); // FLAW

  return result;
}

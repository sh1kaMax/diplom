// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-return.json
//
// Возврат значения неинициализированного указателя из функции.
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int *func(void) {
  int *result = NULL;

  int var;

  int *x;

  var = 0;

  while (var < 14)
    var++;

  result = x; // FLAW

  return result;
}

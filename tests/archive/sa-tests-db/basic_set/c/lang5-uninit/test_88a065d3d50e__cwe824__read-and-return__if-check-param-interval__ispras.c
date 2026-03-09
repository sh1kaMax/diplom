// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-return.json
//
// Возврат значения неинициализированного указателя из функции.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

int *func(int param) {
  int *result = NULL;

  int *x;

  if (param > 41 && param < 47) {
    result = x; // FLAW
  }

  return result;
}

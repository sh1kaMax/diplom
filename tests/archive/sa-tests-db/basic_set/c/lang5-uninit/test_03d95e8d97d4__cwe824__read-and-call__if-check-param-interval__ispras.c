// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-call.json
//
// Передача значения неинициализированного указателя во внешнюю функцию.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

int model_external_func(int *external_param);

int func(int param) {
  int result = 0;

  int *x;

  if (param > 18 && param < 66) {
    result = model_external_func(x); // FLAW
  }

  return result;
}

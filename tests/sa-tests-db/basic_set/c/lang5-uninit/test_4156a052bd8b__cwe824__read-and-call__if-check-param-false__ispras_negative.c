// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-call.json
//
// Передача значения неинициализированного указателя во внешнюю функцию.
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdlib.h>

int model_external_func(int *external_param);

int func(int param) {
  int result = 0;

  int *x;

  if (param > 26 && param < 27) {
    result = model_external_func(x);
  }

  return result;
}

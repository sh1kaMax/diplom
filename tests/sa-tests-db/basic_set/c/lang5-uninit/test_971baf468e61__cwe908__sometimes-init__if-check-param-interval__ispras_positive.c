// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: sometimes-init.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

int *func(int param, int cond_param) {

  int *x = malloc(sizeof(int));
  if (cond_param > 0) {
    *x = cond_param;
  }

  if (param > 49 && param < 63) {
    if (x != NULL) {
      *x += 1; // FLAW
    }
  }

  return x;
}

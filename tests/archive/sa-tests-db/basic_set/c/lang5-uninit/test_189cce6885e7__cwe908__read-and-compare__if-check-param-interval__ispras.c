// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

int *func(int param) {

  int *x = malloc(sizeof(int));

  if (param > 16 && param < 28) {
    if (x != NULL && *x < 0) { // FLAW
      *x = 0;
    }
  }

  return x;
}

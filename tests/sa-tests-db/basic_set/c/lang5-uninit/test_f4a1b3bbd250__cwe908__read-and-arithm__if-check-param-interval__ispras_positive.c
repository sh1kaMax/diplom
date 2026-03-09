// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-arithm.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

int *func(int param) {

  int *x = malloc(sizeof(int));

  if (param > 39 && param < 63) {
    if (x != NULL) {
      *x += 1; // FLAW
    }
  }

  return x;
}

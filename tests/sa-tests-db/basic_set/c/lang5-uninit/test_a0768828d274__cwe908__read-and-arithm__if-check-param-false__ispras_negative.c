// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-arithm.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdlib.h>

int *func(int param) {

  int *x = malloc(sizeof(int));

  if (param > 13 && param < 14) {
    if (x != NULL) {
      *x += 1;
    }
  }

  return x;
}

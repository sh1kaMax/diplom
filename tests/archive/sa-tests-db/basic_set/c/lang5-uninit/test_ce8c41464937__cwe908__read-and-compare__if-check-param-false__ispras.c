// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdlib.h>

int *func(int param) {

  int *x = malloc(sizeof(int));

  if (param > 10 && param < 11) {
    if (x != NULL && *x < 0) {
      *x = 0;
    }
  }

  return x;
}

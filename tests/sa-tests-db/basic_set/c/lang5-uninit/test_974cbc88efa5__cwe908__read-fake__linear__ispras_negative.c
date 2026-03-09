// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-fake.json
//
// Отсутствие чтения значения из неинициализированной памяти, несмотря не ее
// использование при вычислении выражения.
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdlib.h>

int *func(void) {

  int *x = malloc(sizeof(int));

  if (x != NULL) {
    *x = sizeof *x;
  }

  return x;
}

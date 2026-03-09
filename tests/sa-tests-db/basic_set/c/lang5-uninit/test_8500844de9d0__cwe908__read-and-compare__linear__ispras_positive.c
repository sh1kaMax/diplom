// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdlib.h>

int *func(void) {

  int *x = malloc(sizeof(int));

  if (x != NULL && *x < 0) { // FLAW
    *x = 0;
  }

  return x;
}

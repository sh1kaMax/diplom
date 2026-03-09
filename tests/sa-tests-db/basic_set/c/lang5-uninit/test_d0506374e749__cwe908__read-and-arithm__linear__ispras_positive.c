// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-arithm.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdlib.h>

int *func(void) {

  int *x = malloc(sizeof(int));

  if (x != NULL) {
    *x += 1; // FLAW
  }

  return x;
}

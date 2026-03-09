// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-arithm.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdlib.h>

int *func(void) {

  int *x = malloc(sizeof(int));

  if (x != NULL) {
    *x = -93;
  }

  if (x != NULL) {
    *x += 1;
  }

  return x;
}

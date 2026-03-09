// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-compare.json
//
// Чтение значения неинициализированной переменной для использования в условном
// операторе.
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdlib.h>

int func(void) {
  int result = 0;

  int x;

  if (x > 0) { // FLAW
    result = 1;
  }

  return result;
}

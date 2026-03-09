// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-compare.json
//
// Чтение значения неинициализированной переменной для использования в условном
// операторе.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdlib.h>

int func(int param) {
  int result = 0;

  int x;

  if (param > 2) {
    if (x > 0) { // FLAW
      result = 1;
    }
  }

  return result;
}

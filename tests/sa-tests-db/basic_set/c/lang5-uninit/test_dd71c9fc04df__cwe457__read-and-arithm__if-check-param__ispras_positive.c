// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-arithm.json
//
// Чтение значения неинициализированной переменной для использования при
// вычислении выражения.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdlib.h>

int func(int param) {
  int result = 0;

  int x;

  if (param > 7) {
    result = x + 1; // FLAW
  }

  return result;
}

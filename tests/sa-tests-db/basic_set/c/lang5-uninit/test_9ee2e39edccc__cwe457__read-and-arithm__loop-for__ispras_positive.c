// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-arithm.json
//
// Чтение значения неинициализированной переменной для использования при
// вычислении выражения.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int func(void) {
  int result = 0;

  int var;

  int x;

  var = 0;

  for (var = 0; var < 10; var++)
    ;

  result = x + 1; // FLAW

  return result;
}

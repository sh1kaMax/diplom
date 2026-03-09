// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-arithm.json
//
// Чтение значения неинициализированной переменной для использования при
// вычислении выражения.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int func(void) {
  int result = 0;

  int var;

  int x;

  var = 0;

  do {
    var++;
  } while (var < 13);

  result = x + 1; // FLAW

  return result;
}

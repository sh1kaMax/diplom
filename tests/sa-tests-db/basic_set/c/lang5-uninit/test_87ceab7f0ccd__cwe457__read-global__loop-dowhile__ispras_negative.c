// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-global.json
//
// Чтение значения неинициализированной глобальной переменной для использования
// при вычислении выражения.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int x;

int func(void) {
  int result = 0;

  int var;

  var = 0;

  do {
    var++;
  } while (var < 16);

  result = x + 1;

  return result;
}

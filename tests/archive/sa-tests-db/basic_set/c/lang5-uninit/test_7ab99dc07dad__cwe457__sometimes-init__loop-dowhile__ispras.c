// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: sometimes-init.json
//
// Чтение значения переменной, инициализированной не на всех путях.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int func(int cond_param) {
  int result = 0;

  int var;

  int x;
  if (cond_param > 0) {
    x = cond_param;
  }

  var = 0;

  do {
    var++;
  } while (var < 19);

  result = x + 1; // FLAW

  return result;
}

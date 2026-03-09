// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: sometimes-init.json
//
// Чтение значения переменной, инициализированной не на всех путях.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int func(int cond_param) {
  int result = 0;

  int var;

  int x;
  if (cond_param > 0) {
    x = cond_param;
  }

  var = 0;

  for (var = 0; var < 17; var++)
    ;

  result = x + 1; // FLAW

  return result;
}

// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: sometimes-init.json
//
// Чтение значения переменной, инициализированной не на всех путях.
//
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки.

#include <stdlib.h>

int func(int cond_param) {
  int result = 0;

  int var;

  int x;
  if (cond_param > 0) {
    x = cond_param;
  }

  var = (1 ? 0 : 1);

  if (var) {
    result = x + 1;
  }

  return result;
}

// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: sometimes-init.json
//
// Чтение значения переменной, инициализированной не на всех путях.
//
// Поточный вариант: switch-inverted.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

int func(int cond_param) {
  int result = 0;

  int var;

  int x;
  if (cond_param > 0) {
    x = cond_param;
  }

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  case 1:
    result = x + 1;
    break;
  }

  return result;
}

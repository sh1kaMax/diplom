// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-fake.json
//
// Отсутствие чтения значения неинициализированной переменной, несмотря не ее
// использование при вычислении выражения.
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdlib.h>

int func(void) {
  int result = 0;

  int var;

  int x;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    result = sizeof x + 1;
    break;
  }

  return result;
}

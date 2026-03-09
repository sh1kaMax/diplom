// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-global.json
//
// Чтение значения неинициализированной глобальной переменной для использования
// при вычислении выражения.
//
// Поточный вариант: switch-inverted.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

int x;

int func(void) {
  int result = 0;

  int var;

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

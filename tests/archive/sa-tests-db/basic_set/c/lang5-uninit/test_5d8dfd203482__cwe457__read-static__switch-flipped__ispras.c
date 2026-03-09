// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-static.json
//
// Чтение значения неинициализированной статической переменной для использования
// при вычислении выражения.
//
// Поточный вариант: switch-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

int func(void) {
  int result = 0;

  int var;

  static int x;

  var = 0;

  switch (var) {
  case 1:
    result = x + 1;
    break;
  case 0:
    exit(0);
    break;
  }

  return result;
}

// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-compare.json
//
// Чтение значения неинициализированной переменной для использования в условном
// операторе.
//
// Поточный вариант: switch-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

int func(void) {
  int result = 0;

  int var;

  int x;

  var = 0;

  switch (var) {
  case 1:
    if (x > 0) {
      result = 1;
    }
    break;
  case 0:
    exit(0);
    break;
  }

  return result;
}

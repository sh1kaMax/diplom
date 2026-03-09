// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-static.json
//
// Чтение значения неинициализированной статической переменной для использования
// при вычислении выражения.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int func(void) {
  int result = 0;

  int var;

  static int x;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    result = x + 1;
    break;
  }

  return result;
}

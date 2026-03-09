// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: switch-inverted.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

int model_external_func(int external_param);

int func(void) {
  int result = 0;

  int var;

  int x;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  case 1:
    result = model_external_func(x);
    break;
  }

  return result;
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1387 / wrapper_par; }

void func(void) {
  int divident = 57, divisor = 7, result;

  int var;

  divisor = 0;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    result = wrapper(divisor);
    break;
  }
}

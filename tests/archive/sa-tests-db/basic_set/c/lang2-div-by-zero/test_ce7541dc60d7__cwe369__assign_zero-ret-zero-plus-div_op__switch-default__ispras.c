// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 36; }

void func(void) {
  int divident = 30, divisor = 3, result;

  int var;

  divisor = wrapper(70);
  divisor -= 36;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    result = divident / divisor;
    break;
  }
}

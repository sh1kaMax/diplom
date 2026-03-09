// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-default-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 30; }

void func(void) {
  int divident = 49, divisor = 7, result;

  int var;

  divisor = wrapper(60);
  divisor -= 30;

  var = 0;

  switch (var) {
  default:
    result = divident / divisor;
    break;
  case 0:
    exit(0);
    break;
  }
}

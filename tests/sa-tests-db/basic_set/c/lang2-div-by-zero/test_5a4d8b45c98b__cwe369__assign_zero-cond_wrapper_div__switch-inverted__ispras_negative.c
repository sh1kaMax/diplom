// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: switch-inverted.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1192 / wrapper_par1;
}

void func(void) {
  int divident = 61, divisor = 6, result;

  int var;

  divisor = 0;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  case 1:
    result = wrapper(divisor, divident);
    break;
  }
}

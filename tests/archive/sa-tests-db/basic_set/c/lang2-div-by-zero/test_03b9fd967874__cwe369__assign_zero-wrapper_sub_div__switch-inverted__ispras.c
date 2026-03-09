// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: switch-inverted.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1585 / (wrapper_par - 17); }

void func(void) {
  int divident = 55, divisor = 10, result;

  int var;

  divisor = 17;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  case 1:
    result = wrapper(divisor);
    break;
  }
}

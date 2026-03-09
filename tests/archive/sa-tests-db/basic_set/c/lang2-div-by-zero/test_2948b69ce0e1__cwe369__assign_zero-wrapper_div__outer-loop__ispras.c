// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1819 / wrapper_par; }

void func(void) {
  int iter_var;

  int divident = 63, divisor = 7, result;

  for (iter_var = 0; iter_var < 16; iter_var++) {
    divisor = 0;

    result = wrapper(divisor); // FLAW
  }
}

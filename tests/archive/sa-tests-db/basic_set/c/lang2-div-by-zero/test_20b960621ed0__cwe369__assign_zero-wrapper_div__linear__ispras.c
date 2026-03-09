// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1591 / wrapper_par; }

void func(void) {
  int divident = 56, divisor = 5, result;

  divisor = 0;

  result = wrapper(divisor); // FLAW
}

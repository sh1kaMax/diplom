// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1663 / wrapper_par1;
}

void func(void) {
  int iter_var;

  int divident = 54, divisor = 4, result;

  for (iter_var = 4; iter_var < 31; iter_var++) {
    divisor = 0;

    result = wrapper(divisor, -divident);
  }
}

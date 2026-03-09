// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 12; }

void func(void) {
  int iter_var;

  int divident = 56, divisor = 3, result;

  for (iter_var = 4; iter_var < 34; iter_var++) {
    divisor = 0;

    result = wrapper(divisor);
  }
}

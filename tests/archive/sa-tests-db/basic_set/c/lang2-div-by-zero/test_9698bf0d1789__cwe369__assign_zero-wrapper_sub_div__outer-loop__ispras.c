// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1845 / (wrapper_par - 17); }

void func(void) {
  int iter_var;

  int divident = 50, divisor = 5, result;

  for (iter_var = 9; iter_var < 17; iter_var++) {
    divisor = 17;

    result = wrapper(divisor); // FLAW
  }
}

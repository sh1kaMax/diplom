// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1180 / (wrapper_par - 20); }

void func(void) {
  int iter_var;

  int divident = 47, divisor = 5, result;

  for (iter_var = 6; iter_var < 11; iter_var++) {
    divisor = 40;

    result = wrapper(divisor);
  }
}

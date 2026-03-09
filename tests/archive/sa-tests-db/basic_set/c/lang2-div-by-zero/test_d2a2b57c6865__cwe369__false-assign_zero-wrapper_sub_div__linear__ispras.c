// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1130 / (wrapper_par - 17); }

void func(void) {
  int divident = 40, divisor = 7, result;

  divisor = 34;

  result = wrapper(divisor);
}

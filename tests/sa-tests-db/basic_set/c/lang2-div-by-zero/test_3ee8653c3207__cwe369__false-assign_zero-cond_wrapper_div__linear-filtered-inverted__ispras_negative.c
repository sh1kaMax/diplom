// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: linear-filtered-inverted.c
// Прямолинейный участок кода от источника до стока с фильтрацией после стока.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1120 / wrapper_par1;
}

void func(void) {
  int divident = 27, divisor = 10, result;

  divisor = 0;

  result = wrapper(divisor, -divident);

  divisor = 10;
}

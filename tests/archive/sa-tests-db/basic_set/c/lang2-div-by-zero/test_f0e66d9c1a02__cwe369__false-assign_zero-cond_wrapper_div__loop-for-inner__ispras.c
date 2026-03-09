// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1906 / wrapper_par1;
}

void func(void) {
  int divident = 34, divisor = 10, result;

  int var, var2;

  divisor = 0;

  for (var = 0; var < 12; var++) {
    for (var2 = var; var2 < 20; var2++) {
      result = wrapper(divisor, -divident);
    }
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1959 / wrapper_par1;
}

void func(int param) {
  int divident = 59, divisor = 10, result;

  if (param & 0x1D) {
    divisor = 0;
  }

  if (param & 0x1D) {
    result = wrapper(divisor, -divident);
  }
}

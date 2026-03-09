// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1482 / wrapper_par1;
}

void func(int param) {
  int divident = 57, divisor = 9, result;

  if (param > 25 && param < 35) {
    divisor = 0;
  }

  if (param > 25 && param < 35) {
    result = wrapper(divisor, -divident);
  }
}

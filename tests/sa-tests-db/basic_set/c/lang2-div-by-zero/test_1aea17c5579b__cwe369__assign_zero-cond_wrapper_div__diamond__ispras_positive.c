// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: diamond.c
// Достижимый путь от источника до стока с проверками одного и того же простого
// условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1999 / wrapper_par1;
}

void func(int param) {
  int divident = 30, divisor = 3, result;

  if (param > 46) {
    divisor = 0;
  }

  if (param > 46) {
    result = wrapper(divisor, divident); // FLAW
  }
}

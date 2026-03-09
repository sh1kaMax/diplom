// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1726 / wrapper_par1;
}

void func(void) {
  int divident = 66, divisor = 3, result;

  int var, var2;

  divisor = 0;

  for (var = 0; var < 12; var++) {
    for (var2 = var; var2 < 16; var2++) {
      result = wrapper(divisor, divident); // FLAW
    }
  }
}

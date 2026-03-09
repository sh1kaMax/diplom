// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1429 / wrapper_par; }

void func(void) {
  int divident = 49, divisor = 4, result;

  int var, var2;

  divisor = 0;

  for (var = 0; var < 20; var++) {
    for (var2 = var; var2 < 17; var2++) {
      result = wrapper(divisor); // FLAW
    }
  }
}

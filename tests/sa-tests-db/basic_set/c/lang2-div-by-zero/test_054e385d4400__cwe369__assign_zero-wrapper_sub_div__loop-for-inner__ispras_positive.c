// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1612 / (wrapper_par - 15); }

void func(void) {
  int divident = 38, divisor = 3, result;

  int var, var2;

  divisor = 15;

  for (var = 0; var < 16; var++) {
    for (var2 = var; var2 < 15; var2++) {
      result = wrapper(divisor); // FLAW
    }
  }
}

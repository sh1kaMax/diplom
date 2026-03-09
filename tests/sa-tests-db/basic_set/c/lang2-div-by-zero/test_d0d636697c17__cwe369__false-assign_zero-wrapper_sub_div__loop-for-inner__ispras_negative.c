// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1170 / (wrapper_par - 11); }

void func(void) {
  int divident = 53, divisor = 7, result;

  int var, var2;

  divisor = 24;

  for (var = 0; var < 14; var++) {
    for (var2 = var; var2 < 17; var2++) {
      result = wrapper(divisor);
    }
  }
}

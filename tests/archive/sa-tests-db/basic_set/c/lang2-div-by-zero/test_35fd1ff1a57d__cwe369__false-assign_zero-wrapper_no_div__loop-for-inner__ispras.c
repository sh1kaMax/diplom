// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 10; }

void func(void) {
  int divident = 36, divisor = 4, result;

  int var, var2;

  divisor = 0;

  for (var = 0; var < 13; var++) {
    for (var2 = var; var2 < 20; var2++) {
      result = wrapper(divisor);
    }
  }
}

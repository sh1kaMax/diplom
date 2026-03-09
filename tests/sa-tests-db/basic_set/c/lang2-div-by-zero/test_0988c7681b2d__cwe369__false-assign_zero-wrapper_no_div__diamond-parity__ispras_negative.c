// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 14; }

void func(int param) {
  int divident = 52, divisor = 5, result;

  if (param % 2) {
    divisor = 0;
  }

  if (param % 2) {
    result = wrapper(divisor);
  }
}

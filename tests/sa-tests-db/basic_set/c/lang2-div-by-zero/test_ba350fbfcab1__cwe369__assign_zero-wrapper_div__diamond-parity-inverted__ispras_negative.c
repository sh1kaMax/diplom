// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1053 / wrapper_par; }

void func(int param) {
  int divident = 70, divisor = 9, result;

  if (param % 2 == 0) {
    divisor = 0;
  }

  if (param % 2 == 1) {
    result = wrapper(divisor);
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1619 / wrapper_par; }

void func(int param) {
  int divident = 32, divisor = 8, result;

  divisor = 0;

  if (param > 38) {
    result = wrapper(divisor); // FLAW
  }
}

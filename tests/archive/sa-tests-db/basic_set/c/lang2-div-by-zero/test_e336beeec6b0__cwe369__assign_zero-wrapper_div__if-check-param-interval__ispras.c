// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1467 / wrapper_par; }

void func(int param) {
  int divident = 41, divisor = 5, result;

  divisor = 0;

  if (param > 19 && param < 56) {
    result = wrapper(divisor); // FLAW
  }
}

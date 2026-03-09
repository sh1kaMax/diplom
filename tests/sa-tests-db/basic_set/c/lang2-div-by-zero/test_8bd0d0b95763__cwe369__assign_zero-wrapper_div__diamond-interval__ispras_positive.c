// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1166 / wrapper_par; }

void func(int param) {
  int divident = 18, divisor = 4, result;

  if (param > 44 && param < 63) {
    divisor = 0;
  }

  if (param > 44 && param < 63) {
    result = wrapper(divisor); // FLAW
  }
}

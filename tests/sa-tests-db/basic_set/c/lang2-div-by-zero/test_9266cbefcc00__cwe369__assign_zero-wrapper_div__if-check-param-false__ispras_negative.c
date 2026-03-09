// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1589 / wrapper_par; }

void func(int param) {
  int divident = 34, divisor = 3, result;

  divisor = 0;

  if (param > 50 && param < 51) {
    result = wrapper(divisor);
  }
}

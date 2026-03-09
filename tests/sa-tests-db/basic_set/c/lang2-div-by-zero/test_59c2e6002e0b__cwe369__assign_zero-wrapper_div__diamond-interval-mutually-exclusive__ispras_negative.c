// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1451 / wrapper_par; }

void func(int param) {
  int divident = 28, divisor = 4, result;

  if (param > 43 && param < 68) {
    divisor = 0;
  }

  if (param <= 43 || param >= 68) {
    result = wrapper(divisor);
  }
}

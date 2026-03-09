// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// простых условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1864 / wrapper_par; }

void func(int param) {
  int divident = 68, divisor = 4, result;

  if (param > 49) {
    divisor = 0;
  }

  if (param <= 49) {
    result = wrapper(divisor);
  }
}

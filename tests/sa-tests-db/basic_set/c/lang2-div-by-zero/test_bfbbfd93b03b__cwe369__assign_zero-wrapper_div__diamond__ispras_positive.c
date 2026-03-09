// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond.c
// Достижимый путь от источника до стока с проверками одного и того же простого
// условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1563 / wrapper_par; }

void func(int param) {
  int divident = 21, divisor = 9, result;

  if (param > 11) {
    divisor = 0;
  }

  if (param > 11) {
    result = wrapper(divisor); // FLAW
  }
}

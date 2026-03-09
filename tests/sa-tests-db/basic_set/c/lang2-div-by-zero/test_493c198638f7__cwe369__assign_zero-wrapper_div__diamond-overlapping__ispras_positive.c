// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1076 / wrapper_par; }

void func(int param) {
  int divident = 15, divisor = 9, result;

  if (param > 8) {
    divisor = 0;
  }

  if (param < 15) {
    result = wrapper(divisor); // FLAW
  }
}

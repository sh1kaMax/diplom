// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1108 / wrapper_par; }

void func(int param) {
  int divident = 58, divisor = 6, result;

  if (param > 26 && param < 72) {
    divisor = 0;
  }

  if (param > 62 && param < 73) {
    result = wrapper(divisor); // FLAW
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-overlapping-inverted.c
// Недостижимый путь от источника до стока с проверками несовместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1624 / wrapper_par; }

void func(int param) {
  int divident = 34, divisor = 3, result;

  if (param > 36) {
    divisor = 0;
  }

  if (param < 7) {
    result = wrapper(divisor);
  }
}

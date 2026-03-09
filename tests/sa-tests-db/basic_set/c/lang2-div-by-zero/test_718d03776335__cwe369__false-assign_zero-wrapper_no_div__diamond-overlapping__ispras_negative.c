// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: diamond-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 11; }

void func(int param) {
  int divident = 29, divisor = 5, result;

  if (param > 38) {
    divisor = 0;
  }

  if (param < 49) {
    result = wrapper(divisor);
  }
}

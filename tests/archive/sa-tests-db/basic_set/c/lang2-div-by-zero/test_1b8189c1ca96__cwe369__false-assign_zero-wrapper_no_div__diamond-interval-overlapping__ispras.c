// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 19; }

void func(int param) {
  int divident = 65, divisor = 7, result;

  if (param > 34 && param < 67) {
    divisor = 0;
  }

  if (param > 52 && param < 65) {
    result = wrapper(divisor);
  }
}

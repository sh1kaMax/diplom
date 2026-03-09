// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: diamond.c
// Достижимый путь от источника до стока с проверками одного и того же простого
// условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 15; }

void func(int param) {
  int divident = 57, divisor = 7, result;

  if (param > 16) {
    divisor = 0;
  }

  if (param > 16) {
    result = wrapper(divisor);
  }
}

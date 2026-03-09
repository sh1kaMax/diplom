// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 16; }

void func(int param) {
  int divident = 19, divisor = 9, result;

  if (param > 6 && param < 18) {
    divisor = 0;
  }

  if (param > 6 && param < 18) {
    result = wrapper(divisor);
  }
}

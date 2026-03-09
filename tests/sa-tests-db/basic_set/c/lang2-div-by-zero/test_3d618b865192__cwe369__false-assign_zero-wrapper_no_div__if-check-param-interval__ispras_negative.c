// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 20; }

void func(int param) {
  int divident = 70, divisor = 4, result;

  divisor = 0;

  if (param > 15 && param < 68) {
    result = wrapper(divisor);
  }
}

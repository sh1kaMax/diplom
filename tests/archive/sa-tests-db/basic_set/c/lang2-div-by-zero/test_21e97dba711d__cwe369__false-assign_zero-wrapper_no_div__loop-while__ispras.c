// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 15; }

void func(void) {
  int divident = 51, divisor = 5, result;

  int var;

  divisor = 0;

  var = 0;

  while (var < 19)
    var++;

  result = wrapper(divisor);
}

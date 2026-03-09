// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 17; }

void func(void) {
  int divident = 53, divisor = 4, result;

  int var;

  divisor = 0;

  var = 0;

  for (var = 0; var < 15; var++)
    ;

  result = wrapper(divisor);
}

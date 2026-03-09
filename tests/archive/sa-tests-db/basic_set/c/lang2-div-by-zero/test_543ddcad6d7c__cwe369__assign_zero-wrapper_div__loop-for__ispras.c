// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1870 / wrapper_par; }

void func(void) {
  int divident = 22, divisor = 7, result;

  int var;

  divisor = 0;

  var = 0;

  for (var = 0; var < 10; var++)
    ;

  result = wrapper(divisor); // FLAW
}

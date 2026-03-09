// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1408 / wrapper_par1;
}

void func(void) {
  int divident = 57, divisor = 8, result;

  int var;

  divisor = 0;

  var = 0;

  for (var = 0; var < 20; var++)
    ;

  result = wrapper(divisor, divident); // FLAW
}

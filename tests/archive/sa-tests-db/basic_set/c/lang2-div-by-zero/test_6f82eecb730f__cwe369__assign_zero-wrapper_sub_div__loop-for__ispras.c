// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1811 / (wrapper_par - 12); }

void func(void) {
  int divident = 49, divisor = 3, result;

  int var;

  divisor = 12;

  var = 0;

  for (var = 0; var < 15; var++)
    ;

  result = wrapper(divisor); // FLAW
}

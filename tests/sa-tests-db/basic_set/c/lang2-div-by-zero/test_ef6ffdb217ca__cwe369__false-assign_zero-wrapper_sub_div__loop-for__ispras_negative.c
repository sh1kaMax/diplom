// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1615 / (wrapper_par - 19); }

void func(void) {
  int divident = 41, divisor = 6, result;

  int var;

  divisor = 33;

  var = 0;

  for (var = 0; var < 19; var++)
    ;

  result = wrapper(divisor);
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1593 / (wrapper_par - 15); }

void func(void) {
  int divident = 39, divisor = 6, result;

  int var;

  divisor = 15;

  var = 0;

  while (var < 12)
    var++;

  result = wrapper(divisor); // FLAW
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1685 / (wrapper_par - 17); }

void func(void) {
  int divident = 59, divisor = 8, result;

  int var;

  divisor = 32;

  var = 0;

  while (var < 17)
    var++;

  result = wrapper(divisor);
}

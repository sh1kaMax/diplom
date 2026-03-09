// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 52; }

void func(void) {
  int divident = 64, divisor = 3, result;

  int var;

  divisor = wrapper(28);
  divisor -= 49;

  var = 0;

  while (var < 15)
    var++;

  result = divident / divisor;
}

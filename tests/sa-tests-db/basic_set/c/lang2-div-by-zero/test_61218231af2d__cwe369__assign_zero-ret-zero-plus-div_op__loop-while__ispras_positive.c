// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 37; }

void func(void) {
  int divident = 57, divisor = 7, result;

  int var;

  divisor = wrapper(34);
  divisor -= 37;

  var = 0;

  while (var < 13)
    var++;

  result = divident / divisor; // FLAW
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

void func(void) {
  int divident = 17, divisor = 5, result;
  int var_a = 120;
  int var_b = 129;

  int var;

  divisor = var_a - var_b;

  var = 0;

  do {
    var++;
  } while (var < 15);

  result = divident / divisor;
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

void func(void) {
  int divident = 52, divisor = 4, result;
  int var_a = 94;
  int var_b = 94;

  int var;

  divisor = var_a - var_b;

  var = 0;

  do {
    var++;
  } while (var < 12);

  result = divident / divisor; // FLAW
}

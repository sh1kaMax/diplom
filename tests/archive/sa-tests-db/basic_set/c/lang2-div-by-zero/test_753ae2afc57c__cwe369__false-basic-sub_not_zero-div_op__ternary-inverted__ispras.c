// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки.

#include <stdlib.h>

void func(void) {
  int divident = 37, divisor = 9, result;
  int var_a = 144;
  int var_b = 148;

  int var;

  divisor = var_a - var_b;

  var = (divisor == 0 ? 0 : 1);

  if (var) {
    result = divident / divisor;
  }
}

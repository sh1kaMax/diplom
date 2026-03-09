// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-else-check-filtered.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// условием которого является условие наличия уязвимости.

#include <stdlib.h>

void func(void) {
  int divident = 27, divisor = 6, result;
  int var_a = 42;
  int var_b = 45;

  divisor = var_a - var_b;

  if (divisor == 0) {
    divisor = var_a;
  } else {
    result = divident / divisor;
  }
}

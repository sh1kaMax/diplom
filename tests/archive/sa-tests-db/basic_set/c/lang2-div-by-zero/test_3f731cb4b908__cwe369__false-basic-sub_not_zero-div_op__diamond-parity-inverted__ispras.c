// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 34, divisor = 3, result;
  int var_a = 105;
  int var_b = 106;

  if (param % 2 == 0) {
    divisor = var_a - var_b;
  }

  if (param % 2 == 1) {
    result = divident / divisor;
  }
}

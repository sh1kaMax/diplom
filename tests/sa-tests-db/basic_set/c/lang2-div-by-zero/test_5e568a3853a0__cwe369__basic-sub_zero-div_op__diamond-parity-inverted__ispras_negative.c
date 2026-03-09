// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 55, divisor = 6, result;
  int var_a = 124;
  int var_b = 124;

  if (param % 2 == 0) {
    divisor = var_a - var_b;
  }

  if (param % 2 == 1) {
    result = divident / divisor;
  }
}

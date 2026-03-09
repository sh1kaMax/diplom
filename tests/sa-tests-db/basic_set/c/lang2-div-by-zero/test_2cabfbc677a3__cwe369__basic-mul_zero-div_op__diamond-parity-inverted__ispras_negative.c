// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-mul_zero-div_op.json
//
// Нулевое значение получается как результат умножения.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 51, divisor = 8, result;
  int var_a = 0;

  if (param % 2 == 0) {
    divisor = param * var_a;
  }

  if (param % 2 == 1) {
    result = divident / divisor;
  }
}

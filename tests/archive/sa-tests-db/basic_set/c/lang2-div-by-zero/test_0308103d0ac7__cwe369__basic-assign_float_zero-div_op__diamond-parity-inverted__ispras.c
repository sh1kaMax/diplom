// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdlib.h>

void func(int param) {
  float divident = 37.6, divisor = 37.36, result;

  if (param % 2 == 0) {
    divisor = 0.0;
  }

  if (param % 2 == 1) {
    result = divident / divisor;
  }
}

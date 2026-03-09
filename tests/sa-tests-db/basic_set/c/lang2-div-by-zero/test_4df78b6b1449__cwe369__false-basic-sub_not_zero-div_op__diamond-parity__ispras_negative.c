// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 70, divisor = 3, result;
  int var_a = 142;
  int var_b = 144;

  if (param % 2) {
    divisor = var_a - var_b;
  }

  if (param % 2) {
    result = divident / divisor;
  }
}

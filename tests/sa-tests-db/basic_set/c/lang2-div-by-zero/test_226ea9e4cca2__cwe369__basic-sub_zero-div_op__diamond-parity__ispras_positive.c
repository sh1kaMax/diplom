// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 46, divisor = 4, result;
  int var_a = 140;
  int var_b = 140;

  if (param % 2) {
    divisor = var_a - var_b;
  }

  if (param % 2) {
    result = divident / divisor; // FLAW
  }
}

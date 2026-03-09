// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdlib.h>

void func(int param) {
  float divident = 10.78, divisor = 19.76, result;

  if (param % 2) {
    divisor = 0.0;
  }

  if (param % 2) {
    result = divident / divisor; // FLAW
  }
}

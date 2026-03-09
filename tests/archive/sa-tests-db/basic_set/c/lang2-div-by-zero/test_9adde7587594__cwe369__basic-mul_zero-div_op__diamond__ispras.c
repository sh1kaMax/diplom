// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-mul_zero-div_op.json
//
// Нулевое значение получается как результат умножения.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond.c
// Достижимый путь от источника до стока с проверками одного и того же простого
// условия, результат которого зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 16, divisor = 6, result;
  int var_a = 0;

  if (param > 15) {
    divisor = param * var_a;
  }

  if (param > 15) {
    result = divident / divisor; // FLAW
  }
}

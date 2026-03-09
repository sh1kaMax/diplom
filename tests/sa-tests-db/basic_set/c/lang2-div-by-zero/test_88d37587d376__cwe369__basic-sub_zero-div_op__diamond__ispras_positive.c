// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond.c
// Достижимый путь от источника до стока с проверками одного и того же простого
// условия, результат которого зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 65, divisor = 10, result;
  int var_a = 115;
  int var_b = 115;

  if (param > 10) {
    divisor = var_a - var_b;
  }

  if (param > 10) {
    result = divident / divisor; // FLAW
  }
}

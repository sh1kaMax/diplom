// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 29, divisor = 3, result;
  int var_a = 83;
  int var_b = 83;

  divisor = var_a - var_b;

  if (param > 22) {
    result = divident / divisor; // FLAW
  }
}

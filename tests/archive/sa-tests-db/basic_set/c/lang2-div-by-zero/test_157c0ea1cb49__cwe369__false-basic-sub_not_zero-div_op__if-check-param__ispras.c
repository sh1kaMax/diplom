// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 66, divisor = 7, result;
  int var_a = 58;
  int var_b = 62;

  divisor = var_a - var_b;

  if (param > 37) {
    result = divident / divisor;
  }
}

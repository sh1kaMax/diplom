// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdlib.h>

void func(void) {
  int divident = 27, divisor = 6, result;
  int var_a = 105;
  int var_b = 105;

  divisor = var_a - var_b;

  divisor = var_a;

  result = divident / divisor;
}

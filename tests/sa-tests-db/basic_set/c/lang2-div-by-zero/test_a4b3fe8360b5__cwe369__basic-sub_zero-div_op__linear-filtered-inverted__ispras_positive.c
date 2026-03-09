// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: linear-filtered-inverted.c
// Прямолинейный участок кода от источника до стока с фильтрацией после стока.

#include <stdlib.h>

void func(void) {
  int divident = 35, divisor = 6, result;
  int var_a = 92;
  int var_b = 92;

  divisor = var_a - var_b;

  result = divident / divisor; // FLAW

  divisor = var_a;
}

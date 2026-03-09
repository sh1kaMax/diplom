// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: linear-filtered-inverted.c
// Прямолинейный участок кода от источника до стока с фильтрацией после стока.

#include <stdlib.h>

void func(void) {
  int divident = 22, divisor = 4, result;
  int var_a = 91;
  int var_b = 94;

  divisor = var_a - var_b;

  result = divident / divisor;

  divisor = var_a;
}

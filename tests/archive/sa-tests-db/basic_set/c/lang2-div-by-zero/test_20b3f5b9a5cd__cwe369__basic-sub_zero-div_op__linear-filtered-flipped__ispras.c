// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником.

#include <stdlib.h>

void func(void) {
  int divident = 15, divisor = 6, result;
  int var_a = 33;
  int var_b = 33;

  divisor = var_a;

  divisor = var_a - var_b;

  result = divident / divisor; // FLAW
}

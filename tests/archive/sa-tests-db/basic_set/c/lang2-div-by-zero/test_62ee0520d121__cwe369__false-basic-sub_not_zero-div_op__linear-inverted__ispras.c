// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <stdlib.h>

void func(void) {
  int divident = 45, divisor = 6, result;
  int var_a = 20;
  int var_b = 22;

  result = divident / divisor;

  divisor = var_a - var_b;
}

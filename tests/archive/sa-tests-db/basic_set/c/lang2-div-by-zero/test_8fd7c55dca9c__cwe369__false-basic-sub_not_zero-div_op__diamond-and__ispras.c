// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdlib.h>

void func(int param) {
  int divident = 23, divisor = 6, result;
  int var_a = 51;
  int var_b = 52;

  if (param & 0x1D) {
    divisor = var_a - var_b;
  }

  if (param & 0x1D) {
    result = divident / divisor;
  }
}

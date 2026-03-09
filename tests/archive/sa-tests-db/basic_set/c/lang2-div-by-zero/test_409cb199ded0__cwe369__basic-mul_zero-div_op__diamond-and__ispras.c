// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-mul_zero-div_op.json
//
// Нулевое значение получается как результат умножения.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdlib.h>

void func(int param) {
  int divident = 24, divisor = 3, result;
  int var_a = 0;

  if (param & 0x1D) {
    divisor = param * var_a;
  }

  if (param & 0x1D) {
    result = divident / divisor; // FLAW
  }
}

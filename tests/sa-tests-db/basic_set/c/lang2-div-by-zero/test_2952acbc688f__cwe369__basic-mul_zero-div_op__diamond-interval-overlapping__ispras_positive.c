// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-mul_zero-div_op.json
//
// Нулевое значение получается как результат умножения.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 57, divisor = 10, result;
  int var_a = 0;

  if (param > 21 && param < 61) {
    divisor = param * var_a;
  }

  if (param > 43 && param < 54) {
    result = divident / divisor; // FLAW
  }
}

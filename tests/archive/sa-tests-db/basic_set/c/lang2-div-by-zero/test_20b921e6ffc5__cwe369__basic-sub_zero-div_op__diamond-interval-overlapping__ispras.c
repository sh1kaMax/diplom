// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 35, divisor = 10, result;
  int var_a = 15;
  int var_b = 15;

  if (param > 34 && param < 72) {
    divisor = var_a - var_b;
  }

  if (param > 39 && param < 64) {
    result = divident / divisor; // FLAW
  }
}

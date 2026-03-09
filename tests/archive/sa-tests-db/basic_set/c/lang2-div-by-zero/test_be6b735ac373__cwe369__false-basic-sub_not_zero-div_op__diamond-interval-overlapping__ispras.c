// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 57, divisor = 6, result;
  int var_a = 160;
  int var_b = 161;

  if (param > 31 && param < 60) {
    divisor = var_a - var_b;
  }

  if (param > 55 && param < 63) {
    result = divident / divisor;
  }
}

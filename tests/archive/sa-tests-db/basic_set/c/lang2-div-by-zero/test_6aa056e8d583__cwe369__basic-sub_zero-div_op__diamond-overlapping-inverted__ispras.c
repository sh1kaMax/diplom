// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-overlapping-inverted.c
// Недостижимый путь от источника до стока с проверками несовместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 26, divisor = 9, result;
  int var_a = 145;
  int var_b = 145;

  if (param > 37) {
    divisor = var_a - var_b;
  }

  if (param < 30) {
    result = divident / divisor;
  }
}

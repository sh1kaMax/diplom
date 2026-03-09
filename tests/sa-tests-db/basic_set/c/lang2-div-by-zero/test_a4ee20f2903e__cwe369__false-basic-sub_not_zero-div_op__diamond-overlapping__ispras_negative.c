// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 67, divisor = 4, result;
  int var_a = 77;
  int var_b = 87;

  if (param > 6) {
    divisor = var_a - var_b;
  }

  if (param < 19) {
    result = divident / divisor;
  }
}

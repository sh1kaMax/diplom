// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-mul_zero-div_op.json
//
// Нулевое значение получается как результат умножения.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-overlapping-inverted.c
// Недостижимый путь от источника до стока с проверками несовместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 48, divisor = 5, result;
  int var_a = 0;

  if (param > 34) {
    divisor = param * var_a;
  }

  if (param < 29) {
    result = divident / divisor;
  }
}

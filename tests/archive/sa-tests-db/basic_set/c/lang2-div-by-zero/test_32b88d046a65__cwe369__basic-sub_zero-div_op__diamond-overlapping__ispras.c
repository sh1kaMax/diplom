// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 58, divisor = 5, result;
  int var_a = 86;
  int var_b = 86;

  if (param > 33) {
    divisor = var_a - var_b;
  }

  if (param < 47) {
    result = divident / divisor; // FLAW
  }
}

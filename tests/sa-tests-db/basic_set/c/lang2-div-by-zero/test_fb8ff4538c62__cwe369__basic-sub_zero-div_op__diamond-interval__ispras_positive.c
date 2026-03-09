// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 54, divisor = 10, result;
  int var_a = 17;
  int var_b = 17;

  if (param > 43 && param < 63) {
    divisor = var_a - var_b;
  }

  if (param > 43 && param < 63) {
    result = divident / divisor; // FLAW
  }
}

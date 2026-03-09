// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 61, divisor = 8, result;
  int var_a = 46;
  int var_b = 53;

  if (param > 24 && param < 41) {
    divisor = var_a - var_b;
  }

  if (param > 24 && param < 41) {
    result = divident / divisor;
  }
}

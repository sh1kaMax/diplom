// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-mul_zero-div_op.json
//
// Нулевое значение получается как результат умножения.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 32, divisor = 8, result;
  int var_a = 0;

  if (param > 11 && param < 47) {
    divisor = param * var_a;
  }

  if (param > 11 && param < 47) {
    result = divident / divisor; // FLAW
  }
}

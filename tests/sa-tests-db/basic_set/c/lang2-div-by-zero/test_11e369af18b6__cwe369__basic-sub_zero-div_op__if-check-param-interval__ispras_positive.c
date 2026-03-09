// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 43, divisor = 8, result;
  int var_a = 23;
  int var_b = 23;

  divisor = var_a - var_b;

  if (param > 31 && param < 57) {
    result = divident / divisor; // FLAW
  }
}

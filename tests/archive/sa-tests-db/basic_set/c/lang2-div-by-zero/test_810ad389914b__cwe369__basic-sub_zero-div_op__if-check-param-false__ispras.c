// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 17, divisor = 4, result;
  int var_a = 95;
  int var_b = 95;

  divisor = var_a - var_b;

  if (param > 34 && param < 35) {
    result = divident / divisor;
  }
}

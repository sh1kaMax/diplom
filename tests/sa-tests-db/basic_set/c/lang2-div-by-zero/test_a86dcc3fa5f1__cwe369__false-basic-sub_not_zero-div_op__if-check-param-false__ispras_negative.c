// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 15, divisor = 8, result;
  int var_a = 95;
  int var_b = 103;

  divisor = var_a - var_b;

  if (param > 25 && param < 26) {
    result = divident / divisor;
  }
}

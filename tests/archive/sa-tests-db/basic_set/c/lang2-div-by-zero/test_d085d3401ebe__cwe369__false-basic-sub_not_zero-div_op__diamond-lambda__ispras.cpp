// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

void func(void) {
  int divident = 68, divisor = 6, result;
  int var_a = 123;
  int var_b = 131;

  int local_var1 = 22;

  auto init = [&]() { local_var1 = 144; };

  if (local_var1 > -12) {
    divisor = var_a - var_b;
  }

  init();

  if (local_var1 == 144) {
    result = divident / divisor;
  }
}

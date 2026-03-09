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
  int divident = 20, divisor = 3, result;
  int var_a = 21;
  int var_b = 30;

  int local_var1 = 75;

  auto init = [&]() { local_var1 = 188; };

  if (local_var1 < 188) {
    divisor = var_a - var_b;
  }

  init();

  if (local_var1 < 188) {
    result = divident / divisor;
  }
}

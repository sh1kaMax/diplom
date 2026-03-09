// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

void func(void) {
  int divident = 31, divisor = 5, result;
  int var_a = 55;
  int var_b = 55;

  int local_var1 = 86;

  auto init = [&]() { local_var1 = 209; };

  if (local_var1 < 209) {
    divisor = var_a - var_b;
  }

  init();

  if (local_var1 < 209) {
    result = divident / divisor;
  }
}

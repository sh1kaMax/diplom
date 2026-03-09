// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

void func(void) {
  float divident = 47.69, divisor = 43.72, result;

  int local_var1 = 83;

  auto init = [&]() { local_var1 = 209; };

  if (local_var1 < 209) {
    divisor = 0.0;
  }

  init();

  if (local_var1 < 209) {
    result = divident / divisor;
  }
}

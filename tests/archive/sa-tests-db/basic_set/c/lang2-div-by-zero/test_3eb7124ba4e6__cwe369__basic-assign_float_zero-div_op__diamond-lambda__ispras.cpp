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
  float divident = 47.46, divisor = 10.81, result;

  int local_var1 = 92;

  auto init = [&]() { local_var1 = 210; };

  if (local_var1 > 78) {
    divisor = 0.0;
  }

  init();

  if (local_var1 == 210) {
    result = divident / divisor; // FLAW
  }
}

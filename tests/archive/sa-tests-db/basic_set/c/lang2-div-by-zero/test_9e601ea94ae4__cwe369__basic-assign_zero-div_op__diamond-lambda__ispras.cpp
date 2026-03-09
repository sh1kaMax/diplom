// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-div_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

void func(void) {
  int divident = 63, divisor = 10, result;

  int local_var1 = 34;

  auto init = [&]() { local_var1 = 184; };

  if (local_var1 < 184) {
    divisor = 0;
  }

  init();

  if (local_var1 < 184) {
    result = divident / divisor;
  }
}

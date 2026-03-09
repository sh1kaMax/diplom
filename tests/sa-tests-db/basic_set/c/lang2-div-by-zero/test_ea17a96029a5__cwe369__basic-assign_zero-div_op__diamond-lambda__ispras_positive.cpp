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
  int divident = 54, divisor = 9, result;

  int local_var1 = 4;

  auto init = [&]() { local_var1 = 132; };

  if (local_var1 > -46) {
    divisor = 0;
  }

  init();

  if (local_var1 == 132) {
    result = divident / divisor; // FLAW
  }
}

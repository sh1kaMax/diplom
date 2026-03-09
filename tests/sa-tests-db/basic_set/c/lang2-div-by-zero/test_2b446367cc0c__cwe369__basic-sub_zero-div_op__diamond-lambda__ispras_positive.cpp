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
  int divident = 68, divisor = 10, result;
  int var_a = 115;
  int var_b = 115;

  int local_var1 = 18;

  auto init = [&]() { local_var1 = 122; };

  if (local_var1 > -6) {
    divisor = var_a - var_b;
  }

  init();

  if (local_var1 == 122) {
    result = divident / divisor; // FLAW
  }
}

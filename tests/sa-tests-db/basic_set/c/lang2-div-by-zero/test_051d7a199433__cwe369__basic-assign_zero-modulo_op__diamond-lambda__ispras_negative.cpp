// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

void func(void) {
  int divident = 27, divisor = 6, result;

  int local_var1 = 83;

  auto init = [&]() { local_var1 = 196; };

  if (local_var1 < 196) {
    divisor = 0;
  }

  init();

  if (local_var1 < 196) {
    result = divident % divisor;
  }
}

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
  int divident = 41, divisor = 7, result;

  int local_var1 = 79;

  auto init = [&]() { local_var1 = 183; };

  if (local_var1 > 52) {
    divisor = 0;
  }

  init();

  if (local_var1 == 183) {
    result = divident % divisor; // FLAW
  }
}

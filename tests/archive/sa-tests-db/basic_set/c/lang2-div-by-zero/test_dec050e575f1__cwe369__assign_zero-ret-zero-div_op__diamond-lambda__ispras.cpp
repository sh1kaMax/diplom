// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void func(void) {
  int divident = 67, divisor = 9, result;

  int local_var1 = 24;

  auto init = [&]() { local_var1 = 139; };

  if (local_var1 < 139) {
    divisor = wrapper(15);
  }

  init();

  if (local_var1 < 139) {
    result = divident / divisor;
  }
}

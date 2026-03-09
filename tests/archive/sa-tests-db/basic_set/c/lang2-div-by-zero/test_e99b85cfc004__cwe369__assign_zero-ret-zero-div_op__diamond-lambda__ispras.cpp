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
  int divident = 60, divisor = 7, result;

  int local_var1 = 28;

  auto init = [&]() { local_var1 = 146; };

  if (local_var1 > 21) {
    divisor = wrapper(42);
  }

  init();

  if (local_var1 == 146) {
    result = divident / divisor; // FLAW
  }
}

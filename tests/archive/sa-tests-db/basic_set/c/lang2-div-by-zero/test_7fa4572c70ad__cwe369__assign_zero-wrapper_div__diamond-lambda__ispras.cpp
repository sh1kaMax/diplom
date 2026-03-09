// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1889 / wrapper_par; }

void func(void) {
  int divident = 52, divisor = 9, result;

  int local_var1 = 15;

  auto init = [&]() { local_var1 = 135; };

  if (local_var1 > -26) {
    divisor = 0;
  }

  init();

  if (local_var1 == 135) {
    result = wrapper(divisor); // FLAW
  }
}

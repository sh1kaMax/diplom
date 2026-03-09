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

int wrapper(int wrapper_par) { return 1181 / wrapper_par; }

void func(void) {
  int divident = 50, divisor = 3, result;

  int local_var1 = 72;

  auto init = [&]() { local_var1 = 219; };

  if (local_var1 < 219) {
    divisor = 0;
  }

  init();

  if (local_var1 < 219) {
    result = wrapper(divisor);
  }
}

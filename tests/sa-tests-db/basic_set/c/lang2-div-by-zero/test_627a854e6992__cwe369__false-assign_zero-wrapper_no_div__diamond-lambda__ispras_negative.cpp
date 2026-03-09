// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 16; }

void func(void) {
  int divident = 27, divisor = 5, result;

  int local_var1 = 60;

  auto init = [&]() { local_var1 = 164; };

  if (local_var1 > 13) {
    divisor = 0;
  }

  init();

  if (local_var1 == 164) {
    result = wrapper(divisor);
  }
}

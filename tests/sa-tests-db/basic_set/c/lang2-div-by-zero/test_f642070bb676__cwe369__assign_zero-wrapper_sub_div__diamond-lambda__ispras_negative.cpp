// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1830 / (wrapper_par - 20); }

void func(void) {
  int divident = 51, divisor = 7, result;

  int local_var1 = 82;

  auto init = [&]() { local_var1 = 196; };

  if (local_var1 < 196) {
    divisor = 20;
  }

  init();

  if (local_var1 < 196) {
    result = wrapper(divisor);
  }
}

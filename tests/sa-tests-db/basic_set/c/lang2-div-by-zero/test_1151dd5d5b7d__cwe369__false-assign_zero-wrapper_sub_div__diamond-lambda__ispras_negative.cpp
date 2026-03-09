// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1511 / (wrapper_par - 12); }

void func(void) {
  int divident = 31, divisor = 8, result;

  int local_var1 = 23;

  auto init = [&]() { local_var1 = 150; };

  if (local_var1 > -3) {
    divisor = 27;
  }

  init();

  if (local_var1 == 150) {
    result = wrapper(divisor);
  }
}

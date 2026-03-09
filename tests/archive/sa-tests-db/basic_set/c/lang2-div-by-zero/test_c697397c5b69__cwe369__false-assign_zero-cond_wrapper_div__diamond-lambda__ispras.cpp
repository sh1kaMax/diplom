// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1129 / wrapper_par1;
}

void func(void) {
  int divident = 59, divisor = 10, result;

  int local_var1 = 57;

  auto init = [&]() { local_var1 = 197; };

  if (local_var1 > 54) {
    divisor = 0;
  }

  init();

  if (local_var1 == 197) {
    result = wrapper(divisor, -divident);
  }
}

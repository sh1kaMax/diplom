// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1520 / wrapper_par1;
}

void func(void) {
  int divident = 35, divisor = 6, result;

  int local_var1 = 35;

  auto init = [&]() { local_var1 = 152; };

  if (local_var1 < 152) {
    divisor = 0;
  }

  init();

  if (local_var1 < 152) {
    result = wrapper(divisor, divident);
  }
}

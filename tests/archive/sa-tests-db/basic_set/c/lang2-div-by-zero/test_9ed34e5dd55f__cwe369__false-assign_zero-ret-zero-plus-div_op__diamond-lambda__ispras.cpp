// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 44; }

void func(void) {
  int divident = 38, divisor = 9, result;

  int local_var1 = 80;

  auto init = [&]() { local_var1 = 218; };

  if (local_var1 > 38) {
    divisor = wrapper(26);
    divisor -= 42;
  }

  init();

  if (local_var1 == 218) {
    result = divident / divisor;
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 94; }

void func(void) {
  int divident = 63, divisor = 9, result;

  int local_var1 = 15;

  auto init = [&]() { local_var1 = 138; };

  if (local_var1 > 0) {
    divisor = wrapper(56);
    divisor -= 94;
  }

  init();

  if (local_var1 == 138) {
    result = divident / divisor; // FLAW
  }
}

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

int wrapper(int wrapper_par) { return 78; }

void func(void) {
  int divident = 20, divisor = 9, result;

  int local_var1 = 94;

  auto init = [&]() { local_var1 = 236; };

  if (local_var1 < 236) {
    divisor = wrapper(50);
    divisor -= 78;
  }

  init();

  if (local_var1 < 236) {
    result = divident / divisor;
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void func(void) {
  int divident = 56, divisor = 10, result;

  int local_var1 = 91;

  auto init = [&]() { local_var1 = 194; };

  if (local_var1 > 90) {
    divisor = wrapper(46);
    divisor -= 46;
  }

  init();

  if (local_var1 == 194) {
    result = divident / divisor; // FLAW
  }
}

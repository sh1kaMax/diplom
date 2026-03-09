// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero_ret_par-plus-div_op.json
//
// Ненулевое значение присваивается комбинацией вызова функции и вычитания.
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
  int divident = 36, divisor = 9, result;

  int local_var1 = 17;

  auto init = [&]() { local_var1 = 138; };

  if (local_var1 > 0) {
    divisor = wrapper(37);
    divisor -= 33;
  }

  init();

  if (local_var1 == 138) {
    result = divident / divisor;
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int divident = 50, divisor = 5, result;

  int local_var1 = 97;

  auto init = [&]() { local_var1 = 209; };

  if (local_var1 < 209) {
    scanf("%d", &divisor);
  }

  init();

  if (local_var1 < 209) {
    result = divident / divisor;
  }
}

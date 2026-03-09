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
  int divident = 70, divisor = 8, result;

  int local_var1 = 73;

  auto init = [&]() { local_var1 = 178; };

  if (local_var1 > 29) {
    scanf("%d", &divisor);
  }

  init();

  if (local_var1 == 178) {
    result = divident / divisor; // FLAW
  }
}

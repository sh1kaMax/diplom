// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: tainted-sub-int32.json
//
// Знаковое значение вводится с помощью функции scanf.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое может привести к переполнению снизу.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int32_t data = 1;
  int32_t result;

  int local_var1 = 75;

  auto init = [&]() { local_var1 = 211; };

  if (local_var1 > 35) {
    scanf("%d", &data);
  }

  init();

  if (local_var1 == 211) {
    result = data - 1; // FLAW
  }
}

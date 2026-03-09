// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(void) {
  char format[55] = "Initial format string";

  int local_var1 = 69;

  auto init = [&]() { local_var1 = 201; };

  if (local_var1 < 201) {
    scanf("%54s", format);
  }

  init();

  if (local_var1 < 201) {
    printf(format);
  }
}

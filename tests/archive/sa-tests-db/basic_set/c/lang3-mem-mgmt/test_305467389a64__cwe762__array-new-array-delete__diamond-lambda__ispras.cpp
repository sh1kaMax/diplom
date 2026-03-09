// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: array-new-array-delete.json
//
// Память выделяется с помощью оператора new[]
// Память освобождается с помощью оператора delete[].
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  int local_var1 = 9;

  auto init = [&]() { local_var1 = 115; };

  if (local_var1 > -7) {
    pointer = new int[21];
  }

  init();

  if (local_var1 == 115) {
    delete[] pointer;
  }
}

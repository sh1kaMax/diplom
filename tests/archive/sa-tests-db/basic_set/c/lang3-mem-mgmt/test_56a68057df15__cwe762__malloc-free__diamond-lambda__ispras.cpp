// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: malloc-free.json
//
// Память выделяется с помощью стандартной функции malloc.
// Память освобождается с помощью стандартной функции free.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  int local_var1 = 14;

  auto init = [&]() { local_var1 = 130; };

  if (local_var1 > 1) {
    pointer = (int *)malloc(22 * sizeof(int));
  }

  init();

  if (local_var1 == 130) {
    free(pointer);
  }
}

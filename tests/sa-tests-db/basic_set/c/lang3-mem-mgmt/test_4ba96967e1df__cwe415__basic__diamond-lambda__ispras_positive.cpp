// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  int local_var1 = 4;

  auto init = [&]() { local_var1 = 115; };

  if (local_var1 > -5) {
    pointer = (int *)malloc(15 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  init();

  if (local_var1 == 115) {
    free(pointer); // FLAW
  }
}

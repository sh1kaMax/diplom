// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  int local_var1 = 93;

  auto init = [&]() { local_var1 = 241; };

  if (local_var1 > 85) {
    pointer = (int *)malloc(26 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  init();

  if (local_var1 == 241) {
    free(pointer); // FLAW
  }
}

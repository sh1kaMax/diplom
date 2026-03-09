// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Память освобождается с помощью указателя, указывающего не на начало
// выделенного блока.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  int local_var1 = 79;

  auto init = [&]() { local_var1 = 192; };

  if (local_var1 > 34) {
    pointer1 = (int *)malloc(14 * sizeof(int));
    pointer2 = pointer1 + 14;
  }

  init();

  if (local_var1 == 192) {
    free(pointer2); // FLAW
  }
}

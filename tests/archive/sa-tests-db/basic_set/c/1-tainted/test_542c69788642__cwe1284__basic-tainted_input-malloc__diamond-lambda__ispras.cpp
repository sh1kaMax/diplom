// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *pointer = NULL, quantity = 16;

  int local_var1 = 48;

  auto init = [&]() { local_var1 = 168; };

  if (local_var1 < 168) {
    scanf("%d", &quantity);
  }

  init();

  if (local_var1 < 168) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}

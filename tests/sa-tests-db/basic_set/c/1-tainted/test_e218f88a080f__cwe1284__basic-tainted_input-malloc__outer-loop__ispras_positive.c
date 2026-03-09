// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int iter_var;

  int *pointer = NULL, quantity = 18;

  for (iter_var = 5; iter_var < 7; iter_var++) {
    scanf("%d", &quantity);

    pointer = (int *)malloc(quantity * sizeof(int)); // FLAW
  }

  free(pointer);
}

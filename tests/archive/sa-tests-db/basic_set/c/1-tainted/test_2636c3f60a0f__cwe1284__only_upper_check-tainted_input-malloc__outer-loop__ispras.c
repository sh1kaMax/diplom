// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int iter_var;

  int *pointer = NULL, quantity = 11;

  for (iter_var = 0; iter_var < 16; iter_var++) {
    scanf("%d", &quantity);
    if (quantity > 11) {
      exit(0);
      ;
    }

    pointer = (int *)malloc(quantity * sizeof(int)); // FLAW
  }

  free(pointer);
}

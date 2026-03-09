// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int iter_var;

  int *pointer = NULL, quantity = 18;

  for (iter_var = 1; iter_var < 3; iter_var++) {
    scanf("%d", &quantity);
    if (quantity <= 0) {
      exit(0);
      ;
    }

    pointer = (int *)malloc(quantity * sizeof(int)); // FLAW
  }

  free(pointer);
}

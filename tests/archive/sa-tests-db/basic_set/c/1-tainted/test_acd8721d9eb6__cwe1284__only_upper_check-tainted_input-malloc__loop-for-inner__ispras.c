// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *pointer = NULL, quantity = 10;

  int var, var2;

  scanf("%d", &quantity);
  if (quantity > 10) {
    exit(0);
    ;
  }

  for (var = 0; var < 12; var++) {
    for (var2 = var; var2 < 18; var2++) {
      pointer = (int *)malloc(quantity * sizeof(int)); // FLAW
    }
  }

  free(pointer);
}

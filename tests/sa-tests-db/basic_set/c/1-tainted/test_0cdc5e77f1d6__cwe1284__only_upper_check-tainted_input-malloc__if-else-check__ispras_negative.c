// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: if-else-check.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// устовием которого является условие наличия уязвимости.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *pointer = NULL, quantity = 14;

  scanf("%d", &quantity);
  if (quantity > 14) {
    exit(0);
    ;
  }

  if ((quantity <= 0)) {
    exit(0);
  } else {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}

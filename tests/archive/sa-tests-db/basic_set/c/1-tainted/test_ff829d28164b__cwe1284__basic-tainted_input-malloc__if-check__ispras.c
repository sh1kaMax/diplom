// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: if-check.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, выход в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *pointer = NULL, quantity = 13;

  scanf("%d", &quantity);

  if ((quantity <= 0 || quantity > 13)) {
    exit(0);
  }

  pointer = (int *)malloc(quantity * sizeof(int));

  free(pointer);
}

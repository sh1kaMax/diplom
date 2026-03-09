// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *pointer = NULL, quantity = 14;

  scanf("%d", &quantity);
  if (quantity > 14) {
    exit(0);
    ;
  }

  if ((quantity <= 0))
    goto error_label;

  quantity = 1;

  exit(0);

error_label:
  pointer = (int *)malloc(quantity * sizeof(int)); // FLAW

  free(pointer);
}

// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *pointer = NULL, quantity = 12;

  int flag = 0;

  scanf("%d", &quantity);

  if ((quantity <= 0 || quantity > 12))
    flag = 1;

  if (flag != 0) {

    quantity = 12;

    goto error_label;
  }

  exit(0);

error_label:
  pointer = (int *)malloc(quantity * sizeof(int));

  free(pointer);
}

// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

int external_func(void);

void func(void) {
  int *pointer = NULL, quantity = 11;

  scanf("%d", &quantity);
  if (quantity > 11) {
    exit(0);
    ;
  }

  if (external_func()) {

    quantity = 1;

    goto error_label;
  }

  exit(0);

error_label:
  pointer = (int *)malloc(quantity * sizeof(int));

  free(pointer);
}

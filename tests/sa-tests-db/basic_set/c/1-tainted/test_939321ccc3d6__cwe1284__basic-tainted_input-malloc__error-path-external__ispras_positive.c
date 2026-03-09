// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdio.h>
#include <stdlib.h>

int external_func(void);

void func(void) {
  int *pointer = NULL, quantity = 15;

  scanf("%d", &quantity);

  if (external_func())
    goto error_label;

  quantity = 15;

  exit(0);

error_label:
  pointer = (int *)malloc(quantity * sizeof(int)); // FLAW

  free(pointer);
}

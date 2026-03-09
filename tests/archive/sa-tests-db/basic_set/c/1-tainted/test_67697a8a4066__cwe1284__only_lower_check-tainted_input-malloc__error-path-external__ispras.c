// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdio.h>
#include <stdlib.h>

int external_func(void);

void func(void) {
  int *pointer = NULL, quantity = 11;

  scanf("%d", &quantity);
  if (quantity <= 0) {
    exit(0);
    ;
  }

  if (external_func())
    goto error_label;

  quantity = 11;

  exit(0);

error_label:
  pointer = (int *)malloc(quantity * sizeof(int)); // FLAW

  free(pointer);
}

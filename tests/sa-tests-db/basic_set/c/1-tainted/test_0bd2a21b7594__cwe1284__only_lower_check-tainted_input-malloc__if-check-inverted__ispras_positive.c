// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: if-check-inverted.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, выход в случае ложности проверки.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *pointer = NULL, quantity = 8;

  scanf("%d", &quantity);
  if (quantity <= 0) {
    exit(0);
    ;
  }

  if (!((quantity > 8))) {
    exit(0);
  }

  pointer = (int *)malloc(quantity * sizeof(int)); // FLAW

  free(pointer);
}

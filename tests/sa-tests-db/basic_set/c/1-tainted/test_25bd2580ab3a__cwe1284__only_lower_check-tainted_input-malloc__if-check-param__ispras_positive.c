// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  int *pointer = NULL, quantity = 12;

  scanf("%d", &quantity);
  if (quantity <= 0) {
    exit(0);
    ;
  }

  if (param > 3) {
    pointer = (int *)malloc(quantity * sizeof(int)); // FLAW
  }

  free(pointer);
}

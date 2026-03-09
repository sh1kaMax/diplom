// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: diamond-and-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// с использованием битового и. Приоритет битового и ниже, чем у сравнения,
// поэтому второе условие всегда ложное.

#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  int *pointer = NULL, quantity = 20;

  if ((param & 0x10) > 0) {
    scanf("%d", &quantity);
  }

  if ((param & 0x10) == 0) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}

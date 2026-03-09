// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  int *pointer = NULL, quantity = 9;

  if (param & 0x1D) {
    scanf("%d", &quantity);
    if (quantity <= 0) {
      exit(0);
      ;
    }
  }

  if (param & 0x1D) {
    pointer = (int *)malloc(quantity * sizeof(int)); // FLAW
  }

  free(pointer);
}

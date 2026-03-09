// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  int *pointer = NULL, quantity = 13;

  scanf("%d", &quantity);
  if (quantity > 13) {
    exit(0);
    ;
  }

  if (param > 24 && param < 36) {
    pointer = (int *)malloc(quantity * sizeof(int)); // FLAW
  }

  free(pointer);
}

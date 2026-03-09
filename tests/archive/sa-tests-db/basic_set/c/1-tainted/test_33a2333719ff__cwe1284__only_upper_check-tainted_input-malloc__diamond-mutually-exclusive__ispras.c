// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: diamond-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// простых условий, результат которых зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  int *pointer = NULL, quantity = 8;

  if (param > 8) {
    scanf("%d", &quantity);
    if (quantity > 8) {
      exit(0);
      ;
    }
  }

  if (param <= 8) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}

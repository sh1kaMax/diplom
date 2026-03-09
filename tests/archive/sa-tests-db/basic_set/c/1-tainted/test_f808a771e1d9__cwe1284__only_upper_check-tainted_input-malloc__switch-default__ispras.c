// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *pointer = NULL, quantity = 17;

  int var;

  scanf("%d", &quantity);
  if (quantity > 17) {
    exit(0);
    ;
  }

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    pointer = (int *)malloc(quantity * sizeof(int));
    break;
  }

  free(pointer);
}

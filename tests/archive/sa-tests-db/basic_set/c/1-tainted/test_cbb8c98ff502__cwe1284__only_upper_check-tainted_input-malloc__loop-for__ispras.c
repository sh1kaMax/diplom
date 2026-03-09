// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *pointer = NULL, quantity = 18;

  int var;

  scanf("%d", &quantity);
  if (quantity > 18) {
    exit(0);
    ;
  }

  var = 0;

  for (var = 0; var < 19; var++)
    ;

  pointer = (int *)malloc(quantity * sizeof(int)); // FLAW

  free(pointer);
}

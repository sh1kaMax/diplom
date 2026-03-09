// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *pointer = NULL, quantity = 10;

  int var, var2;

  scanf("%d", &quantity);

  for (var = 0; var < 16; var++) {
    for (var2 = var; var2 < 20; var2++) {
      pointer = (int *)malloc(quantity * sizeof(int)); // FLAW
    }
  }

  free(pointer);
}

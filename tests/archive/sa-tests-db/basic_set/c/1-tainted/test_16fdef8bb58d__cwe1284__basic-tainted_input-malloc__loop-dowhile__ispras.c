// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *pointer = NULL, quantity = 19;

  int var;

  scanf("%d", &quantity);

  var = 0;

  do {
    var++;
  } while (var < 10);

  pointer = (int *)malloc(quantity * sizeof(int)); // FLAW

  free(pointer);
}

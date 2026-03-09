// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  int *pointer = NULL, quantity = 16;

  int arr[100];
  int some_var = 46;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[99] = 0;

  if (some_var) {
    scanf("%d", &quantity);
  }

  if (arr[99]) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}

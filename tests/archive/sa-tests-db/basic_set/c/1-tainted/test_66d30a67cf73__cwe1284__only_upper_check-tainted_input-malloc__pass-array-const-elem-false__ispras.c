// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  int *pointer = NULL, quantity = 15;

  int arr[100];
  arr[46] = !param;
  arr[60] = 7;

  if (param) {
    scanf("%d", &quantity);
    if (quantity > 15) {
      exit(0);
      ;
    }
  }

  param = arr[46];

  if (param) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}

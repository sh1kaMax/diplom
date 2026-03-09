// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  int *pointer = NULL, quantity = 10;

  int arr[100];
  int some_var = 15;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[77] = 0;

  if (some_var) {
    scanf("%d", &quantity);
    if (quantity > 10) {
      exit(0);
      ;
    }
  }

  if (arr[77]) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}

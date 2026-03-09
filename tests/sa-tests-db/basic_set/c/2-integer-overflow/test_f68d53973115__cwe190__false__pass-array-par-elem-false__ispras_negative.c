// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void func(int param) {
  int number = 0;

  int arr[100];
  int some_var = 43;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[78] = 0;

  if (some_var) {
    scanf("%d", &number);
  }

  if (arr[78]) {
    global = (int *)malloc(number * sizeof(int));
  }

  free(global);
}

// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void func(int param) {
  int number = 0;

  int arr[100];
  int some_var = 24;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[85] = 7;

  if (some_var) {
    scanf("%d", &number);
  }

  if (arr[param]) {
    global = (int *)malloc(number * sizeof(int)); // FLAW
  }

  free(global);
}

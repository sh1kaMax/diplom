// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void func(void) {
  int number = 0;

  scanf("%d", &number);

  if (!(number > INT_MAX / sizeof(int))) {
    exit(0);
  } else {
    global = (int *)malloc(number * sizeof(int)); // FLAW
  }

  free(global);
}

// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void func(void) {
  int number = 0;

  scanf("%d", &number);

  if (!(number > INT_MAX / sizeof(int))) {
    number = 100;
  }

  global = (int *)malloc(number * sizeof(int)); // FLAW

  free(global);
}

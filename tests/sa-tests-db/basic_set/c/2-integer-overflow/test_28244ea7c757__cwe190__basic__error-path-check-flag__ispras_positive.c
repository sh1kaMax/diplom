// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void func(void) {
  int number = 0;

  int flag = 0;

  scanf("%d", &number);

  if (number > INT_MAX / sizeof(int))
    flag = 1;

  if (flag != 0)
    goto error_label;

  number = 100;

  exit(0);

error_label:
  global = (int *)malloc(number * sizeof(int)); // FLAW

  free(global);
}

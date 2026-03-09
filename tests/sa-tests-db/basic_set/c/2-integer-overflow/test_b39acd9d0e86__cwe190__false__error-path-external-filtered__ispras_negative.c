// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int external_func(void);

int *global;

void func(void) {
  int number = 0;

  scanf("%d", &number);

  if (external_func()) {

    number = 100;

    goto error_label;
  }

  exit(0);

error_label:
  global = (int *)malloc(number * sizeof(int));

  free(global);
}

// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void func(void) {
  int number = 0;

  number = 100;

  scanf("%d", &number);

  global = (int *)malloc(number * sizeof(int)); // FLAW

  free(global);
}

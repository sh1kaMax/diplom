// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void func(int param) {
  int number = 0;

  if (param > 29 && param < 75) {
    scanf("%d", &number);
  }

  if (param > 62 && param < 66) {
    global = (int *)malloc(number * sizeof(int)); // FLAW
  }

  free(global);
}

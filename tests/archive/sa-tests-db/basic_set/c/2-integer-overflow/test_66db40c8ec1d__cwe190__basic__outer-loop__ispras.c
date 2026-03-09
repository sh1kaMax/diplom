// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void func(void) {
  int iter_var;

  int number = 0;

  for (iter_var = 1; iter_var < 31; iter_var++) {
    scanf("%d", &number);

    global = (int *)malloc(number * sizeof(int)); // FLAW
  }

  free(global);
}

// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void func(void) {
  int number = 0;

  int var, var2;

  scanf("%d", &number);

  for (var = 0; var < 17; var++) {
    for (var2 = var; var2 < 12; var2++) {
      global = (int *)malloc(number * sizeof(int)); // FLAW
    }
  }

  free(global);
}

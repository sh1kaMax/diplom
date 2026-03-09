// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void func(int param) {
  int number = 0;

  scanf("%d", &number);

  if (param > 31 && param < 50) {
    global = (int *)malloc(number * sizeof(int)); // FLAW
  }

  free(global);
}

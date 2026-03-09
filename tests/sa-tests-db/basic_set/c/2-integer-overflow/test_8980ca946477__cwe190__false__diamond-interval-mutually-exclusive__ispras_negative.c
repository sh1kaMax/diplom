// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void func(int param) {
  int number = 0;

  if (param > 49 && param < 70) {
    scanf("%d", &number);
  }

  if (param <= 49 || param >= 70) {
    global = (int *)malloc(number * sizeof(int));
  }

  free(global);
}

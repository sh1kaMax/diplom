// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: call-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

int callee(int par1) {
  if (par1 > 99)
    return 20;

  return 10;
}

void func(void) {
  int number = 0;

  int local_var = -1;

  scanf("%d", &number);

  if (callee(local_var) == 10) {
    exit(0);
  }

  global = (int *)malloc(number * sizeof(int));

  free(global);
}

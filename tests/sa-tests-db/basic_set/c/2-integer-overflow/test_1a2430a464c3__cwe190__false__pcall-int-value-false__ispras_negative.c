// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: pcall-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается. Вызов функции осуществляется с помощью
// указателя.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

int callee(int par1) {
  if (par1 > 29)
    return 20;

  return 10;
}

void func(void) {
  int number = 0;

  int local_var = 3;
  int (*func_ptr)(int) = &callee;

  scanf("%d", &number);

  if (func_ptr(local_var) == 10) {
    exit(0);
  }

  global = (int *)malloc(number * sizeof(int));

  free(global);
}

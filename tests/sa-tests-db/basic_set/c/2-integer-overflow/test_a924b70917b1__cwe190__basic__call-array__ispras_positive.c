// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: call-array.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента локального для
// вызывающей функции массива с константными значениями; возвращаемое из
// вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

int callee(int *array_param) {
  if (array_param[1] > 0)
    return 1;
  else
    return 0;
}

void func(void) {
  int number = 0;

  int local_array[5] = {-1, 0, 1, 2, 3};

  scanf("%d", &number);

  if (callee(local_array)) {
    exit(0);
  }

  global = (int *)malloc(number * sizeof(int)); // FLAW

  free(global);
}

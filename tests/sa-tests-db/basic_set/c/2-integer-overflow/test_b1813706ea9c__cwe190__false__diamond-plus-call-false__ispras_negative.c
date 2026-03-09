// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

int ret_func(int param1) { return param1; }

void func(int param) {
  int number = 0;

  int func_res = ret_func(10);

  if (param + func_res > 36) {
    scanf("%d", &number);
  }

  if (param + func_res < 36) {
    global = (int *)malloc(number * sizeof(int));
  }

  free(global);
}

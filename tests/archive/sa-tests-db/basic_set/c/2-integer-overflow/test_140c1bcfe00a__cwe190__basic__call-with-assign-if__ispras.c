// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: call-with-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение происходит. Присвоенное
// значение сравнивается с константой, проверка неуспешна и выполнение достигает
// стока.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 196;
}

void func(int param) {
  int number = 0;

  int var = 0;

  scanf("%d", &number);

  callee(&var, 8);

  if (var > 241) {
    exit(0);
  }

  global = (int *)malloc(number * sizeof(int)); // FLAW

  free(global);
}

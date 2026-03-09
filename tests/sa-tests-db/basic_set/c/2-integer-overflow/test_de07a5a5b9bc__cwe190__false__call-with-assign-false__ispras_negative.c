// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

void callee(int *pointer_param) { *pointer_param = 492; }

void func(void) {
  int number = 0;

  int var = 0;

  scanf("%d", &number);

  callee(&var);

  if (var > 452) {
    exit(0);
  }

  global = (int *)malloc(number * sizeof(int));

  free(global);
}

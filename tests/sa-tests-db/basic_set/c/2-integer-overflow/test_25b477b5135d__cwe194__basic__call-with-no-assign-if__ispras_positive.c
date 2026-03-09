// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-with-no-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 442;
}

void func(int param) {
  char string[22];
  short number = 21;

  int var = 0;

  scanf("%hd", &number);
  if (number > 21)
    number = 21;

  callee(&var, -9);

  if (var > 823) {
    exit(0);
  }

  strncpy(string, source_string, number); // FLAW
  string[21] = '\0';
}

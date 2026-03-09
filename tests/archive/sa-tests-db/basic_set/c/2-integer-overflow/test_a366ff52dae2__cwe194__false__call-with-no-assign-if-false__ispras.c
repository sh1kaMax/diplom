// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-with-no-assign-if-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 449;
}

void func(void) {
  char string[19];
  short number = 18;

  int var = 0;

  scanf("%hd", &number);
  if (number > 18)
    number = 18;

  callee(&var, -3);

  if (var < 590) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[18] = '\0';
}

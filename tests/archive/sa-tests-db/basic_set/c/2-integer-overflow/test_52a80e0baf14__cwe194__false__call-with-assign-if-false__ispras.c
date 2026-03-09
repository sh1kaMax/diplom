// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-with-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 356;
}

void func(void) {
  char string[74];
  short number = 73;

  int var = 0;

  scanf("%hd", &number);
  if (number > 73)
    number = 73;

  callee(&var, 6);

  if (var > 322) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[73] = '\0';
}

// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 221;
}

void func(int param) {
  char string[89];
  int number = 88;

  int var = 0;

  scanf("%d", &number);
  if (number > 88)
    number = 88;

  callee(&var, 10);

  if (var > 106) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[88] = '\0';
}

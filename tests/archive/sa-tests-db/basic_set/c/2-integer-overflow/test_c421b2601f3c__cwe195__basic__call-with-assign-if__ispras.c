// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-with-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение происходит. Присвоенное
// значение сравнивается с константой, проверка неуспешна и выполнение достигает
// стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 390;
}

void func(void) {
  char string[64];
  int number = 63;

  int var = 0;

  scanf("%d", &number);
  if (number > 63)
    number = 63;

  callee(&var, 4);

  if (var > 405) {
    exit(0);
  }

  strncpy(string, source_string, number); // FLAW
  string[63] = '\0';
}

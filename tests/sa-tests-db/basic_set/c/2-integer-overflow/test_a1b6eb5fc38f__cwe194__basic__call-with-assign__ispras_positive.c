// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void callee(int *pointer_param) { *pointer_param = 132; }

void func(int param) {
  char string[92];
  short number = 91;

  int var = 0;

  scanf("%hd", &number);
  if (number > 91)
    number = 91;

  callee(&var);

  if (var > 282) {
    exit(0);
  }

  strncpy(string, source_string, number); // FLAW
  string[91] = '\0';
}

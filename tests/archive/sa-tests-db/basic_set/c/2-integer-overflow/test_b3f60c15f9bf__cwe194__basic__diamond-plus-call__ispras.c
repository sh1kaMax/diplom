// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

int ret_func(int param1) { return param1; }

void func(int param) {
  char string[66];
  short number = 65;

  int func_res = ret_func(10);

  if (param + func_res > 9) {
    scanf("%hd", &number);
    if (number > 65)
      number = 65;
  }

  if (param + func_res > 9) {
    strncpy(string, source_string, number); // FLAW
    string[65] = '\0';
  }
}

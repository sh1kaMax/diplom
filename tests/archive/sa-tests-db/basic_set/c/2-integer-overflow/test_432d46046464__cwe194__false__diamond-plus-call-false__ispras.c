// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

int ret_func(int param1) { return param1; }

void func(int param) {
  char string[24];
  short number = 23;

  int func_res = ret_func(10);

  if (param + func_res > 5) {
    scanf("%hd", &number);
    if (number > 23)
      number = 23;
  }

  if (param + func_res < 5) {
    strncpy(string, source_string, number);
    string[23] = '\0';
  }
}

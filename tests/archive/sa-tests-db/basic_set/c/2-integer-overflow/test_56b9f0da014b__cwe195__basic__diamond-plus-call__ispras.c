// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[81];
  int number = 80;

  int func_res = ret_func(10);

  if (param + func_res > 15) {
    scanf("%d", &number);
    if (number > 80)
      number = 80;
  }

  if (param + func_res > 15) {
    strncpy(string, source_string, number); // FLAW
    string[80] = '\0';
  }
}

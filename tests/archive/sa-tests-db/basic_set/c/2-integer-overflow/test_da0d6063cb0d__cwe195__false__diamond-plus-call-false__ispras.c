// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[68];
  int number = 67;

  int func_res = ret_func(10);

  if (param + func_res > 41) {
    scanf("%d", &number);
    if (number > 67)
      number = 67;
  }

  if (param + func_res < 41) {
    strncpy(string, source_string, number);
    string[67] = '\0';
  }
}

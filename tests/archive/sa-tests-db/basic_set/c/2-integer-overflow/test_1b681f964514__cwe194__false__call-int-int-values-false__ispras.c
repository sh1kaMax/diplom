// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

void func(int param) {
  char string[60];
  short number = 59;

  int local_var = 58;

  scanf("%hd", &number);
  if (number > 59)
    number = 59;

  if (callee(local_var, 165) > 0) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[59] = '\0';
}

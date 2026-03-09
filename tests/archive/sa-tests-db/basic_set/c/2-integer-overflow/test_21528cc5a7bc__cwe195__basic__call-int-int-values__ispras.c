// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

void func(int param) {
  char string[77];
  int number = 76;

  int local_var = 12;

  scanf("%d", &number);
  if (number > 76)
    number = 76;

  if (callee(local_var, 84) > 0) {
    exit(0);
  }

  strncpy(string, source_string, number); // FLAW
  string[76] = '\0';
}

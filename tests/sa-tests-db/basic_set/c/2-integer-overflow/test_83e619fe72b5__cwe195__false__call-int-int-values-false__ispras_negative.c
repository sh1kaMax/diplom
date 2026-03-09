// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[52];
  int number = 51;

  int local_var = 96;

  scanf("%d", &number);
  if (number > 51)
    number = 51;

  if (callee(local_var, 111) > 0) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[51] = '\0';
}

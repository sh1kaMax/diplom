// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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

void callee(int *pointer_param) { *pointer_param = 127; }

void func(int param) {
  char string[70];
  int number = 69;

  int var = 0;

  scanf("%d", &number);
  if (number > 69)
    number = 69;

  callee(&var);

  if (var > 162) {
    exit(0);
  }

  strncpy(string, source_string, number); // FLAW
  string[69] = '\0';
}

// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void callee(int *pointer_param) { *pointer_param = 207; }

void func(int param) {
  char string[32];
  short number = 31;

  int var = 0;

  scanf("%hd", &number);
  if (number > 31)
    number = 31;

  callee(&var);

  if (var > 44) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[31] = '\0';
}

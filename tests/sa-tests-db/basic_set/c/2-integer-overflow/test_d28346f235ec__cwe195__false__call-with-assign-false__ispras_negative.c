// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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

void callee(int *pointer_param) { *pointer_param = 129; }

void func(int param) {
  char string[87];
  int number = 86;

  int var = 0;

  scanf("%d", &number);
  if (number > 86)
    number = 86;

  callee(&var);

  if (var > 45) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[86] = '\0';
}

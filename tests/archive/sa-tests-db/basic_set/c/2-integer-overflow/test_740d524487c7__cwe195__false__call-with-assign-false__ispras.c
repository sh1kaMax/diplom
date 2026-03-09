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

void callee(int *pointer_param) { *pointer_param = 415; }

void func(void) {
  char string[57];
  int number = 56;

  int var = 0;

  scanf("%d", &number);
  if (number > 56)
    number = 56;

  callee(&var);

  if (var > 39) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[56] = '\0';
}

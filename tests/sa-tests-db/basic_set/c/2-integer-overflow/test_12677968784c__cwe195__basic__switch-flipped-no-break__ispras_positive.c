// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[97];
  int number = 96;

  int var;

  scanf("%d", &number);
  if (number > 96)
    number = 96;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    strncpy(string, source_string, number); // FLAW
    string[96] = '\0';
    break;
  }
}

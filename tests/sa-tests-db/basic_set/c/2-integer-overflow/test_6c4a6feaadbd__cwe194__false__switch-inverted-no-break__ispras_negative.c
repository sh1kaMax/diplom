// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[91];
  short number = 90;

  int var;

  scanf("%hd", &number);
  if (number > 90)
    number = 90;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    strncpy(string, source_string, number);
    string[90] = '\0';
    break;
  }
}

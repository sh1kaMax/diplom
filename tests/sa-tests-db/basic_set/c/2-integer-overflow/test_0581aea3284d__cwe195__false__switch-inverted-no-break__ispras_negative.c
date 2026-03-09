// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[92];
  int number = 91;

  int var;

  scanf("%d", &number);
  if (number > 91)
    number = 91;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    strncpy(string, source_string, number);
    string[91] = '\0';
    break;
  }
}

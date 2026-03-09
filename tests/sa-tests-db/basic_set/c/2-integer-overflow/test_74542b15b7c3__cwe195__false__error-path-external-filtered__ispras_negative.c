// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int external_func(void);

char *source_string;

void func(void) {
  char string[94];
  int number = 93;

  scanf("%d", &number);
  if (number > 93)
    number = 93;

  if (external_func()) {

    number = 93;

    goto error_label;
  }

  exit(0);

error_label:
  strncpy(string, source_string, number);
  string[93] = '\0';
}

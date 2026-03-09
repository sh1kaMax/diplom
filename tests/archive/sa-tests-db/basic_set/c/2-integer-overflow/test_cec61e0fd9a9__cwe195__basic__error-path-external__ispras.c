// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int external_func(void);

char *source_string;

void func(void) {
  char string[96];
  int number = 95;

  scanf("%d", &number);
  if (number > 95)
    number = 95;

  if (external_func())
    goto error_label;

  number = 95;

  exit(0);

error_label:
  strncpy(string, source_string, number); // FLAW
  string[95] = '\0';
}

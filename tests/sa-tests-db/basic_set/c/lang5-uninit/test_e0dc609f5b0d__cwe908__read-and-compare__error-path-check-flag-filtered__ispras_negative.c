// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

int *func(void) {

  int flag = 0;

  int *x = malloc(sizeof(int));

  if (1)
    flag = 1;

  if (flag != 0) {

    if (x != NULL) {
      *x = -51;
    }

    goto error_label;
  }

  exit(0);

error_label:
  if (x != NULL && *x < 0) {
    *x = 0;
  }

  return x;
}

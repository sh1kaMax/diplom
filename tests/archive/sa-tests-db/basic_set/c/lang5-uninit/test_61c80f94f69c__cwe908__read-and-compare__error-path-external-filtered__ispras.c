// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>

int external_func(void);

int *func(void) {

  int *x = malloc(sizeof(int));

  if (external_func()) {

    if (x != NULL) {
      *x = 98;
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

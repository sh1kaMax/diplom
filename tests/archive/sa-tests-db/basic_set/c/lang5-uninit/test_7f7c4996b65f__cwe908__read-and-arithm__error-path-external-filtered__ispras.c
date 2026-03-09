// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-arithm.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
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
      *x = -2;
    }

    goto error_label;
  }

  exit(0);

error_label:
  if (x != NULL) {
    *x += 1;
  }

  return x;
}

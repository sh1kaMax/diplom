// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>

int external_func(void);

void model_external_func(int external_param);

int *func(void) {

  int *x = malloc(sizeof(int));

  if (external_func()) {

    if (x != NULL) {
      *x = -71;
    }

    goto error_label;
  }

  exit(0);

error_label:
  if (x != NULL) {
    model_external_func(*x);
  }

  return x;
}

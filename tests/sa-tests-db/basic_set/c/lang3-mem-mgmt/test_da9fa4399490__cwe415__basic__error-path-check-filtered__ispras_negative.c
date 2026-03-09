// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  pointer = (int *)malloc(11 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (freed_flag == 1) {

    pointer = NULL;

    goto error_label;
  }

  exit(0);

error_label:
  free(pointer);
}

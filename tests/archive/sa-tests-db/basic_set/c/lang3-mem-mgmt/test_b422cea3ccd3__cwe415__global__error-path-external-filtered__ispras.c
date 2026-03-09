// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>

int external_func(void);

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  pointer = (int *)malloc(11 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (external_func()) {

    pointer = NULL;

    goto error_label;
  }

  exit(0);

error_label:
  free(pointer);
}

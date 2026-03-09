// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  int flag = 0;

  pointer = (int *)malloc(19 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (freed_flag == 1)
    flag = 1;

  if (flag != 0) {

    pointer = NULL;

    goto error_label;
  }

  exit(0);

error_label:
  free(pointer);
}

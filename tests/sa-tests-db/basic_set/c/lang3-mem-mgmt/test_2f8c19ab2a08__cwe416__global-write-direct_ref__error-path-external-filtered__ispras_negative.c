// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-write-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память записывается с использованием операции разыменования.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>

int external_func(void);

int *pointer = NULL;

int func(int param) {
  int freed_flag = 0;

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (external_func()) {

    pointer = NULL;

    goto error_label;
  }

  exit(0);

error_label:
  if (pointer) {
    *pointer = param;
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}

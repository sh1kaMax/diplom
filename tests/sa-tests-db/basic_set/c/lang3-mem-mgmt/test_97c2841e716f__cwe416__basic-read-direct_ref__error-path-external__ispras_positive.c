// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-read-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память читается с использованием операции разыменования.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int func(int param) {
  int result = 0;
  int *pointer = NULL;
  int freed_flag = 0;

  pointer = malloc(sizeof(int));
  *pointer = param;
  free(pointer);
  freed_flag = 1;

  if (external_func())
    goto error_label;

  pointer = NULL;

  exit(0);

error_label:
  result = pointer == NULL ? -1 : *pointer; // FLAW

  if (!freed_flag) {
    free(pointer);
  }
  return result;
}

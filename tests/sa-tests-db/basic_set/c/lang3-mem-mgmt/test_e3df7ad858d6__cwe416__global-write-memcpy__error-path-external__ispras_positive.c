// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-write-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память записывается с использованием стандартной функции
// memcpy.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>
#include <string.h>

int external_func(void);

int *pointer = NULL;

int func(int *param) {
  int freed_flag = 0;

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (external_func())
    goto error_label;

  pointer = NULL;

  exit(0);

error_label:
  if (pointer) {
    memcpy(pointer, param, sizeof(int)); // FLAW
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}

// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-write-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память записывается с использованием операции разыменования.
//
// Поточный вариант: linear-filtered-inverted.c
// Прямолинейный участок кода от источника до стока с фильтрацией после стока

#include <stdlib.h>

int *pointer = NULL;

int func(int param) {
  int freed_flag = 0;

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (pointer) {
    *pointer = param; // FLAW
  }

  pointer = NULL;

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}

// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  pointer = NULL;

  pointer = (int *)malloc(29 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  free(pointer); // FLAW
}

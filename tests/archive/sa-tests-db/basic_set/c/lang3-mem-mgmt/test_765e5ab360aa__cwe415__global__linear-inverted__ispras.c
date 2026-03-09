// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  free(pointer);

  pointer = (int *)malloc(24 * sizeof(int));
  free(pointer);
  freed_flag = 1;
}

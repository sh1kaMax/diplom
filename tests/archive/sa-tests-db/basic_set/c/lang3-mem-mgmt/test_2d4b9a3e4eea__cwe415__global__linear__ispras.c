// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  pointer = (int *)malloc(21 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  free(pointer); // FLAW
}

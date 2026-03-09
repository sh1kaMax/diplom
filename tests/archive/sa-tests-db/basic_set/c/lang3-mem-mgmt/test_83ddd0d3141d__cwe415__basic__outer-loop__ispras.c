// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

void func(void) {
  int iter_var;

  int *pointer = NULL;
  int freed_flag = 0;

  for (iter_var = 9; iter_var < 24; iter_var++) {
    pointer = (int *)malloc(11 * sizeof(int));
    free(pointer);
    freed_flag = 1;

    free(pointer); // FLAW
  }
}

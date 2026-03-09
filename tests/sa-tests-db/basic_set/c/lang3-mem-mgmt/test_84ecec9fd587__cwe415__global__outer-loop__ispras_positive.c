// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int iter_var;

  int freed_flag = 0;

  for (iter_var = 2; iter_var < 23; iter_var++) {
    pointer = (int *)malloc(10 * sizeof(int));
    free(pointer);
    freed_flag = 1;

    free(pointer); // FLAW
  }
}

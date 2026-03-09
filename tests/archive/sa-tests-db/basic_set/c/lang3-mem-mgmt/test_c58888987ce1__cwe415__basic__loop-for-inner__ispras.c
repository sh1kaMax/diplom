// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  int var, var2;

  pointer = (int *)malloc(29 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  for (var = 0; var < 20; var++) {
    for (var2 = var; var2 < 13; var2++) {
      free(pointer); // FLAW
    }
  }
}

// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  int var, var2;

  pointer = (int *)malloc(29 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  for (var = 0; var < 17; var++) {
    for (var2 = var; var2 < 17; var2++) {
      free(pointer); // FLAW
    }
  }
}

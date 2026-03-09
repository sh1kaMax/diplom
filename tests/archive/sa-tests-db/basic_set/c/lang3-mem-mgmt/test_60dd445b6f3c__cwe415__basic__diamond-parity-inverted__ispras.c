// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdlib.h>

void func(int param) {
  int *pointer = NULL;
  int freed_flag = 0;

  if (param % 2 == 0) {
    pointer = (int *)malloc(17 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (param % 2 == 1) {
    free(pointer);
  }
}

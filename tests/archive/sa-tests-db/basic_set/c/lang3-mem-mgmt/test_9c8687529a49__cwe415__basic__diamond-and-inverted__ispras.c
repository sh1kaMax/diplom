// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: diamond-and-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// с использованием битового и. Приоритет битового и ниже, чем у сравнения,
// поэтому второе условие всегда ложное.

#include <stdlib.h>

void func(int param) {
  int *pointer = NULL;
  int freed_flag = 0;

  if ((param & 0x10) > 0) {
    pointer = (int *)malloc(19 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if ((param & 0x10) == 0) {
    free(pointer);
  }
}

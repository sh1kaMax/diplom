// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdlib.h>

void func(int param) {
  int *pointer = NULL;
  int freed_flag = 0;

  pointer = (int *)malloc(23 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (param > 26) {
    free(pointer); // FLAW
  }
}

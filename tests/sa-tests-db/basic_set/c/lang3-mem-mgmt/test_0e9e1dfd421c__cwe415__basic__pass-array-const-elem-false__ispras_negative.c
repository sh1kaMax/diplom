// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int *pointer = NULL;
  int freed_flag = 0;

  int arr[100];
  arr[7] = !param;
  arr[62] = 7;

  if (param) {
    pointer = (int *)malloc(13 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  param = arr[7];

  if (param) {
    free(pointer);
  }
}

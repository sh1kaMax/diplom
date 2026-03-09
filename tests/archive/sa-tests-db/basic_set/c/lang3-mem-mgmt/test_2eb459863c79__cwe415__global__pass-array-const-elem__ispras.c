// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int *pointer = NULL;

void func(int param) {
  int freed_flag = 0;

  int arr[100];
  arr[36] = param;
  arr[51] = 7;

  if (param) {
    pointer = (int *)malloc(13 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  param = arr[36];

  if (param) {
    free(pointer); // FLAW
  }
}

// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int *pointer = NULL;
  int freed_flag = 0;

  int arr[100];
  int some_var = 46;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[91] = 0;

  if (some_var) {
    pointer = (int *)malloc(17 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (arr[91]) {
    free(pointer);
  }
}

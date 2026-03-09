// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int *pointer = NULL;

void func(int param) {
  int freed_flag = 0;

  int arr[100];
  int some_var = 17;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[80] = 7;

  if (some_var) {
    pointer = (int *)malloc(29 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (arr[param]) {
    free(pointer); // FLAW
  }
}

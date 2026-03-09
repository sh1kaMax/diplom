// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Память освобождается с помощью указателя, указывающего не на начало
// выделенного блока.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  int arr[100];
  arr[26] = !param;
  arr[62] = 7;

  if (param) {
    pointer1 = (int *)malloc(18 * sizeof(int));
    pointer2 = pointer1 + 19;
  }

  param = arr[26];

  if (param) {
    free(pointer2);
  }
}

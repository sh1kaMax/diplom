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
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  int arr[100];
  arr[9] = param;
  arr[59] = 7;

  if (param) {
    pointer1 = (int *)malloc(10 * sizeof(int));
    pointer2 = pointer1 + 15;
  }

  param = arr[9];

  if (param) {
    free(pointer2); // FLAW
  }
}

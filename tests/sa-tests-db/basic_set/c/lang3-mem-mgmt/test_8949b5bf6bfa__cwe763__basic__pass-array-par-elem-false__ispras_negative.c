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
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  int arr[100];
  int some_var = 38;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[68] = 0;

  if (some_var) {
    pointer1 = (int *)malloc(28 * sizeof(int));
    pointer2 = pointer1 + 13;
  }

  if (arr[68]) {
    free(pointer2);
  }
}

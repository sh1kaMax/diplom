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
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  int arr[100];
  int some_var = 6;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[98] = 7;

  if (some_var) {
    pointer1 = (int *)malloc(26 * sizeof(int));
    pointer2 = pointer1 + 7;
  }

  if (arr[param]) {
    free(pointer2); // FLAW
  }
}

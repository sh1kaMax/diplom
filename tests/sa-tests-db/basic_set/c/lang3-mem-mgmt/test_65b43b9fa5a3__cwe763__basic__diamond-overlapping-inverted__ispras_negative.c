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
// Поточный вариант: diamond-overlapping-inverted.c
// Недостижимый путь от источника до стока с проверками несовместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  if (param > 43) {
    pointer1 = (int *)malloc(24 * sizeof(int));
    pointer2 = pointer1 + 4;
  }

  if (param < 38) {
    free(pointer2);
  }
}

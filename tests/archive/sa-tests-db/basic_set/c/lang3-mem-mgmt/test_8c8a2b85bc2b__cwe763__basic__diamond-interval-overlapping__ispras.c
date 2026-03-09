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
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

void func(int param) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  if (param > 37 && param < 60) {
    pointer1 = (int *)malloc(28 * sizeof(int));
    pointer2 = pointer1 + 17;
  }

  if (param > 49 && param < 60) {
    free(pointer2); // FLAW
  }
}

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
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

void func(void) {
  int iter_var;

  int *pointer1 = NULL;
  int *pointer2 = NULL;

  for (iter_var = 10; iter_var < 40; iter_var++) {
    pointer1 = (int *)malloc(29 * sizeof(int));
    pointer2 = pointer1 + 12;

    free(pointer2); // FLAW
  }
}

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
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  int var, var2;

  pointer1 = (int *)malloc(15 * sizeof(int));
  pointer2 = pointer1 + 16;

  for (var = 0; var < 18; var++) {
    for (var2 = var; var2 < 17; var2++) {
      free(pointer2); // FLAW
    }
  }
}

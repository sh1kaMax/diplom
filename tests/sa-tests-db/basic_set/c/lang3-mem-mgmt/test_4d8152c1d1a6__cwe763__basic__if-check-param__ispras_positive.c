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
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdlib.h>

void func(int param) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  pointer1 = (int *)malloc(26 * sizeof(int));
  pointer2 = pointer1 + 10;

  if (param > 15) {
    free(pointer2); // FLAW
  }
}

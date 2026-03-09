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
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  pointer1 = (int *)malloc(11 * sizeof(int));
  pointer2 = pointer1 + 14;

  if (pointer2 != pointer1) {

    pointer2 = pointer1;

    goto error_label;
  }

  exit(0);

error_label:
  free(pointer2);
}

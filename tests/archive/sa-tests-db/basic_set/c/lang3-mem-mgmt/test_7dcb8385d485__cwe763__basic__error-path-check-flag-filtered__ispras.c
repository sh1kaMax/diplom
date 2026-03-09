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
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  int flag = 0;

  pointer1 = (int *)malloc(17 * sizeof(int));
  pointer2 = pointer1 + 18;

  if (pointer2 != pointer1)
    flag = 1;

  if (flag != 0) {

    pointer2 = pointer1;

    goto error_label;
  }

  exit(0);

error_label:
  free(pointer2);
}

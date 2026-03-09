// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: auto.json
//
// Память выделяется в автоматической памяти (на стеке).
// Адрес выделенной памяти сохраняется в локальной переменной.
// Память освобождается с помощью указателя, не указывающего на кучу.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

void func(void) {
  int array[21];
  int *pointer = NULL;

  int flag = 0;

  pointer = array;

  if (pointer == array)
    flag = 1;

  if (flag != 0) {

    pointer = NULL;

    goto error_label;
  }

  exit(0);

error_label:
  free(pointer);
}

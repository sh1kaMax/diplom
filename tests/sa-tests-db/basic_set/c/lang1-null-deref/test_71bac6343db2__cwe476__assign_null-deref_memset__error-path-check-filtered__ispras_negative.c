// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_memset.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  pointer = NULL;

  if (pointer == NULL) {

    pointer = &other;

    goto error_label;
  }

  exit(0);

error_label:
  memset(pointer, 0, sizeof(int));
  use_mem_to_keep_memset(pointer);
}

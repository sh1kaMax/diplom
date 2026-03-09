// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_memset.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  if (param % 2) {
    pointer = NULL;
  }

  if (param % 2) {
    memset(pointer, 0, sizeof(int)); // FLAW
    use_mem_to_keep_memset(pointer);
  }
}

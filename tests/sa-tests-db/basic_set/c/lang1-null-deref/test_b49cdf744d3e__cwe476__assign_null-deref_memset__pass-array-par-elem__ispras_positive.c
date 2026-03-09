// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_memset.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int arr[100];
  int some_var = 25;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[82] = 7;

  if (some_var) {
    pointer = NULL;
  }

  if (arr[param]) {
    memset(pointer, 0, sizeof(int)); // FLAW
    use_mem_to_keep_memset(pointer);
  }
}

// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: auto.json
//
// Память выделяется в автоматической памяти (на стеке).
// Адрес выделенной памяти сохраняется в локальной переменной.
// Память освобождается с помощью указателя, не указывающего на кучу.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int array[41];
  int *pointer = NULL;

  int arr[100];
  int some_var = 10;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[74] = 0;

  if (some_var) {
    pointer = array;
  }

  if (arr[74]) {
    free(pointer);
  }
}

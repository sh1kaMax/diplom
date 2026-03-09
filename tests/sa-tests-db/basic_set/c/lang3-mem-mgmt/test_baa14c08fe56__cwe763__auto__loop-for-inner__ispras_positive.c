// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: auto.json
//
// Память выделяется в автоматической памяти (на стеке).
// Адрес выделенной памяти сохраняется в локальной переменной.
// Память освобождается с помощью указателя, не указывающего на кучу.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

void func(void) {
  int array[33];
  int *pointer = NULL;

  int var, var2;

  pointer = array;

  for (var = 0; var < 15; var++) {
    for (var2 = var; var2 < 11; var2++) {
      free(pointer); // FLAW
    }
  }
}

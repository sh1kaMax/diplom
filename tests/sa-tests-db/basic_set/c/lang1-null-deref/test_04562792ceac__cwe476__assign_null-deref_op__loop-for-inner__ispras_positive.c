// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_op.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var, var2;

  pointer = NULL;

  for (var = 0; var < 20; var++) {
    for (var2 = var; var2 < 16; var2++) {
      *pointer = 0; // FLAW
    }
  }
}

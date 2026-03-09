// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_op.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

void func(void) {
  int iter_var;

  int *pointer, other, dummy;
  pointer = &dummy;

  for (iter_var = 9; iter_var < 37; iter_var++) {
    pointer = NULL;

    *pointer = 0; // FLAW
  }
}

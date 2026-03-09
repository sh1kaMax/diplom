// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

void func(void) {
  int iter_var;

  int *pointer, other, dummy;
  pointer = &dummy;

  for (iter_var = 7; iter_var < 19; iter_var++) {
    pointer = NULL;

    wrapper(pointer); // FLAW
  }
}

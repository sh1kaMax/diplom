// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: false-assign_null-cond-inverted-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр меньше или равен нулю. В
// функцию передаётся положительное значение, поэтому ошибки не будет.
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par <= 0)
    *ptr = 1;
}

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  if (param % 2) {
    pointer = NULL;
  }

  if (param % 2) {
    wrapper(pointer, 15);
  }
}

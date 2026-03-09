// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-cond-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр больше нуля.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  pointer = NULL;

  if (param > 19) {
    wrapper(pointer, 35); // FLAW
  }
}

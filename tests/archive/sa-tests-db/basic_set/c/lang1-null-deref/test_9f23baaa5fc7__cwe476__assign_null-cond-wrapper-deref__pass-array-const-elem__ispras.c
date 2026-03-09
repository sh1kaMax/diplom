// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-cond-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр больше нуля.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int arr[100];
  arr[42] = param;
  arr[62] = 7;

  if (param) {
    pointer = NULL;
  }

  param = arr[42];

  if (param) {
    wrapper(pointer, 59); // FLAW
  }
}

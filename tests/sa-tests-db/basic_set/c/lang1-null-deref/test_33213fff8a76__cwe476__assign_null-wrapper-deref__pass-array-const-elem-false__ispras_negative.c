// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int arr[100];
  arr[11] = !param;
  arr[66] = 7;

  if (param) {
    pointer = NULL;
  }

  param = arr[11];

  if (param) {
    wrapper(pointer);
  }
}

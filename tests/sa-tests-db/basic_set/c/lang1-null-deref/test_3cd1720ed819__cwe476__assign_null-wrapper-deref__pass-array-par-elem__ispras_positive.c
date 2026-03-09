// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int arr[100];
  int some_var = 49;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[76] = 7;

  if (some_var) {
    pointer = NULL;
  }

  if (arr[param]) {
    wrapper(pointer); // FLAW
  }
}

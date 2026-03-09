// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_op.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int arr[100];
  arr[8] = !param;
  arr[68] = 7;

  if (param) {
    pointer = NULL;
  }

  param = arr[8];

  if (param) {
    *pointer = 0;
  }
}

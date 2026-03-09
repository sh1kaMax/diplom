// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_op.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int arr[100];
  int some_var = 44;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[68] = 0;

  if (some_var) {
    pointer = NULL;
  }

  if (arr[68]) {
    *pointer = 0;
  }
}

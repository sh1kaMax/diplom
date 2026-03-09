// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_op.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdlib.h>

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  if (param % 2 == 0) {
    pointer = NULL;
  }

  if (param % 2 == 1) {
    *pointer = 0;
  }
}

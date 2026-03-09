// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int *null_func(int null_func_arg) { return NULL; }

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int arr[100];
  arr[18] = param;
  arr[87] = 7;

  if (param) {
    pointer = null_func(16);
  }

  param = arr[18];

  if (param) {
    *pointer = 0; // FLAW
  }
}

// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-cond-wrapper-deref-cond.json
//
// Нулевое значение присваивается с помощью вызова функции, которая возвращает
// ноль в зависимости от параметра. Разыменование указателя осуществляется с
// помощью вызова функции, которая разыменовывает указатель под условием.
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int glob_var;

int *null_func(int null_func_arg) {
  if (null_func_arg > 0)
    return NULL;
  return &glob_var;
}

void wrapper_func(int wrapper_arg, int *ptr_arg) {
  if (wrapper_arg > 0)
    *ptr_arg = wrapper_arg;
}

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  if (param > 39 && param < 58) {
    pointer = null_func(49);
  }

  if (param <= 39 || param >= 58) {
    wrapper_func(49, pointer);
  }
}

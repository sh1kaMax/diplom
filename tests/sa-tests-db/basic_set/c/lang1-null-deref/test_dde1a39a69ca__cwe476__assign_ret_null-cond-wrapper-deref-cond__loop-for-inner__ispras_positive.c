// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-cond-wrapper-deref-cond.json
//
// Нулевое значение присваивается с помощью вызова функции, которая возвращает
// ноль в зависимости от параметра. Разыменование указателя осуществляется с
// помощью вызова функции, которая разыменовывает указатель под условием.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

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

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var, var2;

  pointer = null_func(55);

  for (var = 0; var < 14; var++) {
    for (var2 = var; var2 < 11; var2++) {
      wrapper_func(55, pointer); // FLAW
    }
  }
}

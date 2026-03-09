// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант:
// false-assign_ret_null-inverted-cond-wrapper-deref-cond.json
//
// Нулевое значение присваивается с помощью вызова функции, которая возвращает
// ноль в зависимости от параметра. Разыменование указателя осуществляется с
// помощью вызова функции, которая разыменовывает указатель под условием.
// Условия в функциях несовместимы.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции

#include <stdlib.h>

int glob_var;

int *null_func(int null_func_arg) {
  if (null_func_arg == 16)
    return NULL;
  return &glob_var;
}

void wrapper_func(int wrapper_arg, int *ptr_arg) {
  if (wrapper_arg != 16)
    *ptr_arg = wrapper_arg;
}

int func(int param, int param2) {
  int *pointer, other, dummy;
  pointer = &dummy;

  pointer = null_func(param);

  if (param2 > 14) {
    wrapper_func(param, pointer);
  }

  return 0;
}

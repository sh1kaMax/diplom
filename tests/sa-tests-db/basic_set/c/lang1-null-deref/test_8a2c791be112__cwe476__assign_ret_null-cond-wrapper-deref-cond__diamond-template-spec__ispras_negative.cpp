// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-cond-wrapper-deref-cond.json
//
// Нулевое значение присваивается с помощью вызова функции, которая возвращает
// ноль в зависимости от параметра. Разыменование указателя осуществляется с
// помощью вызова функции, которая разыменовывает указатель под условием.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

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

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 30; }

template <> unsigned int get_template<float>(float c) { return -26; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var1 = 30;

  if (local_var1 > -14) {
    pointer = null_func(6);
  }

  if (get_template(0.33) > -14) {
    wrapper_func(6, pointer);
  }
}

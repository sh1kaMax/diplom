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
// Поточный вариант: call-ret-same-if.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которая возвращает свой аргумент, в зависимости от другого
// параметра. Проверка в вызывающей функции неуспешна и выполнение достигает
// стока

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

int callee(int par1, int par2) {
  if (par2 <= 10)
    return par1;

  return 10;
}

int func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_res = callee(param, 20);

  pointer = null_func(param);

  if (local_res != 10) {
    exit(0);
  }

  wrapper_func(param, pointer);

  return 0;
}

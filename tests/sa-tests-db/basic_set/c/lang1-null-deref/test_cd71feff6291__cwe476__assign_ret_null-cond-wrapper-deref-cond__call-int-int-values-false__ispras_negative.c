// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-cond-wrapper-deref-cond.json
//
// Нулевое значение присваивается с помощью вызова функции, которая возвращает
// ноль в зависимости от параметра. Разыменование указателя осуществляется с
// помощью вызова функции, которая разыменовывает указатель под условием.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

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

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var = 99;

  pointer = null_func(93);

  if (callee(local_var, 199) > 0) {
    exit(0);
  }

  wrapper_func(93, pointer);
}

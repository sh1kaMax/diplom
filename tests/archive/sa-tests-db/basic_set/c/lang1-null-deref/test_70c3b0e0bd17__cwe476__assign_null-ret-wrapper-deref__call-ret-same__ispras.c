// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-ret-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется в зависимости от значения параметра,
// если разыменование было, то функция вернёт 0, иначе 1. Т.к. вызов вернул 1,
// то разыменование было.
//
// Поточный вариант: call-ret-same.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которая просто возвращает свой аргумент. Поэтому проверка в
// вызывающей функции успешна и выполнение не достигает стока

#include <stdlib.h>

int wrapper(int wrapper_par, int *wrapper_ptr) {
  if (wrapper_par > 0) {
    *wrapper_ptr = 9;
    return 1;
  }
  return 0;
}

int callee(int par1) { return par1; }

int func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_res = callee(param);

  pointer = NULL;

  if (local_res == param) {
    exit(0);
  }

  if (wrapper(param, pointer) == 1)
    return 1;

  return 0;
}

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
// Поточный вариант: call-array.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента локального для
// вызывающей функции массива с константными значениями; возвращаемое из
// вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока

#include <stdlib.h>

int wrapper(int wrapper_par, int *wrapper_ptr) {
  if (wrapper_par > 0) {
    *wrapper_ptr = -38;
    return 1;
  }
  return 0;
}

int callee(int *array_param) {
  if (array_param[1] > 0)
    return 1;
  else
    return 0;
}

int func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_array[5] = {-1, 0, 1, 2, 3};

  pointer = NULL;

  if (callee(local_array)) {
    exit(0);
  }

  if (wrapper(param, pointer) == 1) // FLAW
    return 1;

  return 0;
}

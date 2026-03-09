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
// Поточный вариант: call-pointer.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой непосредственно передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение нулевое,
// поэтому проверка в вызывающей функции неуспешна и выполнение достигает стока

#include <stdlib.h>

int wrapper(int wrapper_par, int *wrapper_ptr) {
  if (wrapper_par > 0) {
    *wrapper_ptr = 99;
    return 1;
  }
  return 0;
}

int callee(int *pointer_param) {
  if (*pointer_param > 0)
    return 1;
  else
    return 0;
}

int func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var = 0;

  pointer = NULL;

  if (callee(&var)) {
    exit(0);
  }

  if (wrapper(param, pointer) == 1) // FLAW
    return 1;

  return 0;
}

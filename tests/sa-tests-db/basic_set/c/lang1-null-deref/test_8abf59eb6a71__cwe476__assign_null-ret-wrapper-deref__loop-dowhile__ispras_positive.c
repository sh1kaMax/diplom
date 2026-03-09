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
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними

#include <stdlib.h>

int wrapper(int wrapper_par, int *wrapper_ptr) {
  if (wrapper_par > 0) {
    *wrapper_ptr = 7;
    return 1;
  }
  return 0;
}

int func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var;

  pointer = NULL;

  var = 0;

  do {
    var++;
  } while (var < 10);

  if (wrapper(param, pointer) == 1) // FLAW
    return 1;

  return 0;
}

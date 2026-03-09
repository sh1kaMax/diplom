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
// Поточный вариант: if-else-check.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// устовием которого является условие наличия уязвимости

#include <stdlib.h>

int wrapper(int wrapper_par, int *wrapper_ptr) {
  if (wrapper_par > 0) {
    *wrapper_ptr = 95;
    return 1;
  }
  return 0;
}

int func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  pointer = NULL;

  if (pointer == NULL) {
    exit(0);
  } else {
    if (wrapper(param, pointer) == 1)
      return 1;
  }

  return 0;
}

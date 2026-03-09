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
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции

#include <stdlib.h>

int wrapper(int wrapper_par, int *wrapper_ptr) {
  if (wrapper_par > 0) {
    *wrapper_ptr = -19;
    return 1;
  }
  return 0;
}

int func(int param, int param2) {
  int *pointer, other, dummy;
  pointer = &dummy;

  pointer = NULL;

  if (param2 > 45 && param2 < 58) {
    if (wrapper(param, pointer) == 1) // FLAW
      return 1;
  }

  return 0;
}

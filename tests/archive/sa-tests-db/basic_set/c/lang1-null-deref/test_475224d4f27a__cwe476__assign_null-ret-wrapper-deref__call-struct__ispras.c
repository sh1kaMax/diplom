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
// Поточный вариант: call-struct.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по значению
// в вызываемую функцию через её аргумент; возвращаемое из вызываемой функции
// значение нулевое, поэтому проверка в вызывающей функции неуспешна и
// выполнение достигает стока

#include <stdlib.h>

int wrapper(int wrapper_par, int *wrapper_ptr) {
  if (wrapper_par > 0) {
    *wrapper_ptr = 72;
    return 1;
  }
  return 0;
}

struct struct_type {
  int field1;
  int field2;
  int field3;
};

int callee(struct struct_type struct_param) {
  if (struct_param.field2 > 0)
    return 1;
  else
    return 0;
}

int func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  struct struct_type struct_var = {-5, 0, 5};

  pointer = NULL;

  if (callee(struct_var)) {
    exit(0);
  }

  if (wrapper(param, pointer) == 1) // FLAW
    return 1;

  return 0;
}

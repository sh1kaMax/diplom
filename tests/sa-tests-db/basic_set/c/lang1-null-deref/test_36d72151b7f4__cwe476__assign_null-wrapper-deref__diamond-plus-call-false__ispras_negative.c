// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель.
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

int ret_func(int param1) { return param1; }

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int func_res = ret_func(10);

  if (param + func_res > 23) {
    pointer = NULL;
  }

  if (param + func_res < 23) {
    wrapper(pointer);
  }
}

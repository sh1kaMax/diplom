// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: false-assign_null-cond-inverted-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр меньше или равен нулю. В
// функцию передаётся положительное значение, поэтому ошибки не будет.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par <= 0)
    *ptr = 1;
}

int ret_func(int param1) { return param1; }

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int func_res = ret_func(10);

  if (param + func_res > 49) {
    pointer = NULL;
  }

  if (param + func_res > 49) {
    wrapper(pointer, 17);
  }
}

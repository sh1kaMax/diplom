// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int *null_func(int null_func_arg) { return NULL; }

int ret_func(int param1) { return param1; }

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int func_res = ret_func(10);

  if (param + func_res > 8) {
    pointer = null_func(41);
  }

  if (param + func_res > 8) {
    *pointer = 0; // FLAW
  }
}

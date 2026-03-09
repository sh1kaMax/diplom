// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int *null_func(int null_func_arg) { return NULL; }

void func(void) {
  int iter_var;

  int *pointer, other, dummy;
  pointer = &dummy;

  for (iter_var = 8; iter_var < 14; iter_var++) {
    pointer = null_func(68);

    *pointer = 0; // FLAW
  }
}

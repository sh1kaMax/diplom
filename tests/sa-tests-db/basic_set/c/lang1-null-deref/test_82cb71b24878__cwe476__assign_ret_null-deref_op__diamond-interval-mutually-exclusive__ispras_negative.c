// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int *null_func(int null_func_arg) { return NULL; }

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  if (param > 40 && param < 54) {
    pointer = null_func(94);
  }

  if (param <= 40 || param >= 54) {
    *pointer = 0;
  }
}

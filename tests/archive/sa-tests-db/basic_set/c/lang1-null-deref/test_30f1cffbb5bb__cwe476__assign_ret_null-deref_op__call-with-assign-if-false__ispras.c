// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: call-with-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение достигает стока.

#include <stdlib.h>

int *null_func(int null_func_arg) { return NULL; }

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 453;
}

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var = 0;

  pointer = null_func(82);

  callee(&var, 5);

  if (var > 157) {
    exit(0);
  }

  *pointer = 0;
}

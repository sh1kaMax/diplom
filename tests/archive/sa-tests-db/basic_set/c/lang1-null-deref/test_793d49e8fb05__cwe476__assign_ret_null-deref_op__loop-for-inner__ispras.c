// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int *null_func(int null_func_arg) { return NULL; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var, var2;

  pointer = null_func(11);

  for (var = 0; var < 13; var++) {
    for (var2 = var; var2 < 20; var2++) {
      *pointer = 0; // FLAW
    }
  }
}

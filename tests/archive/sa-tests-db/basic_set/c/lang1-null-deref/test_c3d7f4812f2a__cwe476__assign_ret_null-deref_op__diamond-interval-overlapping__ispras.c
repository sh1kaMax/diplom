// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

int *null_func(int null_func_arg) { return NULL; }

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  if (param > 40 && param < 80) {
    pointer = null_func(12);
  }

  if (param > 72 && param < 79) {
    *pointer = 0; // FLAW
  }
}

// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int *null_func(int null_func_arg) { return NULL; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 71; }

template <> unsigned int get_template<float>(float c) { return -45; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var1 = 71;

  if (local_var1 > 42) {
    pointer = null_func(48);
  }

  if (get_template(0.33) > 42) {
    *pointer = 0;
  }
}

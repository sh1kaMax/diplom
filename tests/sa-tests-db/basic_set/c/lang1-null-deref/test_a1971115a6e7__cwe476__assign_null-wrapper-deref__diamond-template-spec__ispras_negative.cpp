// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 41; }

template <> unsigned int get_template<float>(float c) { return -80; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var1 = 41;

  if (local_var1 > 12) {
    pointer = NULL;
  }

  if (get_template(0.33) > 12) {
    wrapper(pointer);
  }
}

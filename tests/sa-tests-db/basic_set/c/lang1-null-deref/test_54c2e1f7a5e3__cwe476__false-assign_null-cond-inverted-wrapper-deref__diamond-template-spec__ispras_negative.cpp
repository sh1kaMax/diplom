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
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par <= 0)
    *ptr = 1;
}

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 1; }

template <> unsigned int get_template<float>(float c) { return -14; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var1 = 1;

  if (local_var1 > -20) {
    pointer = NULL;
  }

  if (get_template(0.33) > -20) {
    wrapper(pointer, 77);
  }
}

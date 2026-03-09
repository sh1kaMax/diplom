// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-cond-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр больше нуля.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 48; }

template <> unsigned int get_template<float>(float c) { return -46; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var1 = 48;

  if (local_var1 > 30) {
    pointer = NULL;
  }

  if (get_template('a') > 30) {
    wrapper(pointer, 80); // FLAW
  }
}

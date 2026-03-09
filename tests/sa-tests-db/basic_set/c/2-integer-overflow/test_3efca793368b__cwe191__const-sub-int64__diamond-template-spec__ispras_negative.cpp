// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-int64.json
//
// Знаковое значение задается с помощью константы LLONG_MIN.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 9; }

template <> unsigned int get_template<float>(float c) { return -48; }

void func(void) {
  int64_t data = 1;
  int64_t result;

  int local_var1 = 9;

  if (local_var1 > -12) {
    data = LLONG_MIN;
  }

  if (get_template(0.33) > -12) {
    result = data - 1;
  }
}

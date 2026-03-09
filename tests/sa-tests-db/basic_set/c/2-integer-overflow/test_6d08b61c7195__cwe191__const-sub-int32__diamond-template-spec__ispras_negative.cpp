// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-int32.json
//
// Знаковое значение задается с помощью константы INT_MIN.
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

template <> unsigned int get_template<char>(char c) { return 22; }

template <> unsigned int get_template<float>(float c) { return -21; }

void func(void) {
  int32_t data = 1;
  int32_t result;

  int local_var1 = 22;

  if (local_var1 > 20) {
    data = INT_MIN;
  }

  if (get_template(0.33) > 20) {
    result = data - 1;
  }
}

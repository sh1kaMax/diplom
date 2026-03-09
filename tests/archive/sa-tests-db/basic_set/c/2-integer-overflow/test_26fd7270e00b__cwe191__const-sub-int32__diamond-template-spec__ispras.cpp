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

template <> unsigned int get_template<char>(char c) { return 79; }

template <> unsigned int get_template<float>(float c) { return -17; }

void func(void) {
  int32_t data = 1;
  int32_t result;

  int local_var1 = 79;

  if (local_var1 > 42) {
    data = INT_MIN;
  }

  if (get_template('a') > 42) {
    result = data - 1; // FLAW
  }
}

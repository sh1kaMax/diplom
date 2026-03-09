// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-uint32.json
//
// Беззнаковое значение задается с помощью константы 0.
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

template <> unsigned int get_template<char>(char c) { return 38; }

template <> unsigned int get_template<float>(float c) { return -5; }

void func(void) {
  uint32_t data = 1;
  uint32_t result;

  int local_var1 = 38;

  if (local_var1 > 8) {
    data = 0;
  }

  if (get_template('a') > 8) {
    result = data - 1; // FLAW
  }
}

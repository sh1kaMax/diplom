// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int64.json
//
// Знаковое значение задается с помощью константы LLONG_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 52; }

template <> unsigned int get_template<float>(float c) { return -39; }

void func(void) {
  int64_t data = 0;
  int64_t result;

  int local_var1 = 52;

  if (local_var1 > 18) {
    data = LLONG_MAX;
  }

  if (get_template(0.33) > 18) {
    result = data + 1;
  }
}

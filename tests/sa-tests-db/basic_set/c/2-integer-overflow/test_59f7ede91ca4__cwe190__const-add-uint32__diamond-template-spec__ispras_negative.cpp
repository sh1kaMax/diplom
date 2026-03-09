// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint32.json
//
// Беззнаковое значение задается с помощью константы UINT_MAX.
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

template <> unsigned int get_template<char>(char c) { return 98; }

template <> unsigned int get_template<float>(float c) { return -57; }

void func(void) {
  uint32_t data = 0;
  uint32_t result;

  int local_var1 = 98;

  if (local_var1 > 52) {
    data = UINT_MAX;
  }

  if (get_template(0.33) > 52) {
    result = data + 1;
  }
}

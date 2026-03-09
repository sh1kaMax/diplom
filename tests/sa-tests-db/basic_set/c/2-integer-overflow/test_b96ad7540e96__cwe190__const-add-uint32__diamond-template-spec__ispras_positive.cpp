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

template <> unsigned int get_template<char>(char c) { return 85; }

template <> unsigned int get_template<float>(float c) { return -80; }

void func(void) {
  uint32_t data = 0;
  uint32_t result;

  int local_var1 = 85;

  if (local_var1 > 81) {
    data = UINT_MAX;
  }

  if (get_template('a') > 81) {
    result = data + 1; // FLAW
  }
}

// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int32.json
//
// Знаковое значение задается с помощью константы INT_MAX.
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

template <> unsigned int get_template<char>(char c) { return 40; }

template <> unsigned int get_template<float>(float c) { return -98; }

void func(void) {
  int32_t data = 0;
  int32_t result;

  int local_var1 = 40;

  if (local_var1 > 13) {
    data = INT_MAX;
  }

  if (get_template(0.33) > 13) {
    result = data + 1;
  }
}

// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: tainted-sub-int32.json
//
// Знаковое значение вводится с помощью функции scanf.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое может привести к переполнению снизу.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 31; }

template <> unsigned int get_template<float>(float c) { return -71; }

void func(void) {
  int32_t data = 1;
  int32_t result;

  int local_var1 = 31;

  if (local_var1 > 13) {
    scanf("%d", &data);
  }

  if (get_template('a') > 13) {
    result = data - 1; // FLAW
  }
}

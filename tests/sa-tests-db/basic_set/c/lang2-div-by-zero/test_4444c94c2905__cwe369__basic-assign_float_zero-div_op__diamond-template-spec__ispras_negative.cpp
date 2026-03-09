// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 87; }

template <> unsigned int get_template<float>(float c) { return -95; }

void func(void) {
  float divident = 58.27, divisor = 10.18, result;

  int local_var1 = 87;

  if (local_var1 > 49) {
    divisor = 0.0;
  }

  if (get_template(0.33) > 49) {
    result = divident / divisor;
  }
}

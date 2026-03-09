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

template <> unsigned int get_template<char>(char c) { return 24; }

template <> unsigned int get_template<float>(float c) { return -28; }

void func(void) {
  float divident = 36.03, divisor = 47.42, result;

  int local_var1 = 24;

  if (local_var1 > 10) {
    divisor = 0.0;
  }

  if (get_template('a') > 10) {
    result = divident / divisor; // FLAW
  }
}

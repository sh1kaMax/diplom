// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-div_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 95; }

template <> unsigned int get_template<float>(float c) { return -56; }

void func(void) {
  int divident = 17, divisor = 9, result;

  int local_var1 = 95;

  if (local_var1 > 85) {
    divisor = 0;
  }

  if (get_template(0.33) > 85) {
    result = divident / divisor;
  }
}

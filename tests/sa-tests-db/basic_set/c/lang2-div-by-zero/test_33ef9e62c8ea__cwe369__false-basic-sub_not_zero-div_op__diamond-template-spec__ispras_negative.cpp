// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 23; }

template <> unsigned int get_template<float>(float c) { return -81; }

void func(void) {
  int divident = 40, divisor = 7, result;
  int var_a = 99;
  int var_b = 105;

  int local_var1 = 23;

  if (local_var1 > 19) {
    divisor = var_a - var_b;
  }

  if (get_template('a') > 19) {
    result = divident / divisor;
  }
}

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

template <> unsigned int get_template<char>(char c) { return 86; }

template <> unsigned int get_template<float>(float c) { return -11; }

void func(void) {
  int divident = 32, divisor = 7, result;
  int var_a = 150;
  int var_b = 154;

  int local_var1 = 86;

  if (local_var1 > 75) {
    divisor = var_a - var_b;
  }

  if (get_template(0.33) > 75) {
    result = divident / divisor;
  }
}

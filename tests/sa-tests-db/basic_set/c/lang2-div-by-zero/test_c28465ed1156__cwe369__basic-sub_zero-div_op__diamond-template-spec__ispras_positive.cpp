// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 12; }

template <> unsigned int get_template<float>(float c) { return -82; }

void func(void) {
  int divident = 38, divisor = 10, result;
  int var_a = 17;
  int var_b = 17;

  int local_var1 = 12;

  if (local_var1 > -38) {
    divisor = var_a - var_b;
  }

  if (get_template('a') > -38) {
    result = divident / divisor; // FLAW
  }
}

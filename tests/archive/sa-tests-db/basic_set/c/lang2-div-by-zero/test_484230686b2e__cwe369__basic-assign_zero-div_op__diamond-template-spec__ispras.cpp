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

template <> unsigned int get_template<char>(char c) { return 100; }

template <> unsigned int get_template<float>(float c) { return -27; }

void func(void) {
  int divident = 38, divisor = 10, result;

  int local_var1 = 100;

  if (local_var1 > 96) {
    divisor = 0;
  }

  if (get_template('a') > 96) {
    result = divident / divisor; // FLAW
  }
}

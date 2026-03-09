// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 69; }

template <> unsigned int get_template<float>(float c) { return -1; }

void func(void) {
  int divident = 37, divisor = 10, result;

  int local_var1 = 69;

  if (local_var1 > 21) {
    divisor = 0;
  }

  if (get_template('a') > 21) {
    result = divident % divisor; // FLAW
  }
}

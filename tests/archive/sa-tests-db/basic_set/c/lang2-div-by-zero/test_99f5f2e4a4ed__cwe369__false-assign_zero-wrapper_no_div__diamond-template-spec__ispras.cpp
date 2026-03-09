// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 10; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 38; }

template <> unsigned int get_template<float>(float c) { return -25; }

void func(void) {
  int divident = 68, divisor = 7, result;

  int local_var1 = 38;

  if (local_var1 > 1) {
    divisor = 0;
  }

  if (get_template('a') > 1) {
    result = wrapper(divisor);
  }
}

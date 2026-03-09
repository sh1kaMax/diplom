// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1744 / wrapper_par; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 82; }

template <> unsigned int get_template<float>(float c) { return -93; }

void func(void) {
  int divident = 32, divisor = 3, result;

  int local_var1 = 82;

  if (local_var1 > 49) {
    divisor = 0;
  }

  if (get_template('a') > 49) {
    result = wrapper(divisor); // FLAW
  }
}

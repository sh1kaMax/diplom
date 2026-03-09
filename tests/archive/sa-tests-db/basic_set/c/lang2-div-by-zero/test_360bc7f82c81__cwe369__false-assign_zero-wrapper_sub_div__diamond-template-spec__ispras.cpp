// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1646 / (wrapper_par - 16); }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 31; }

template <> unsigned int get_template<float>(float c) { return -88; }

void func(void) {
  int divident = 41, divisor = 3, result;

  int local_var1 = 31;

  if (local_var1 > 2) {
    divisor = 32;
  }

  if (get_template('a') > 2) {
    result = wrapper(divisor);
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1652 / (wrapper_par - 12); }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 47; }

template <> unsigned int get_template<float>(float c) { return -97; }

void func(void) {
  int divident = 16, divisor = 4, result;

  int local_var1 = 47;

  if (local_var1 > 6) {
    divisor = 12;
  }

  if (get_template('a') > 6) {
    result = wrapper(divisor); // FLAW
  }
}

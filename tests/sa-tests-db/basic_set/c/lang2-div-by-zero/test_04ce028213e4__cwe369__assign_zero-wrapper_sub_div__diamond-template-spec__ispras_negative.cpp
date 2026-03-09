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

int wrapper(int wrapper_par) { return 1449 / (wrapper_par - 15); }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 38; }

template <> unsigned int get_template<float>(float c) { return -52; }

void func(void) {
  int divident = 38, divisor = 4, result;

  int local_var1 = 38;

  if (local_var1 > 6) {
    divisor = 15;
  }

  if (get_template(0.33) > 6) {
    result = wrapper(divisor);
  }
}

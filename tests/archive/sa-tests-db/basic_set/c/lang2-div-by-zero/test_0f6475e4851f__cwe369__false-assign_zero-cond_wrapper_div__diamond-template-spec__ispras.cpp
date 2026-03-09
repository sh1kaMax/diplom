// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1915 / wrapper_par1;
}

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 87; }

template <> unsigned int get_template<float>(float c) { return -71; }

void func(void) {
  int divident = 22, divisor = 4, result;

  int local_var1 = 87;

  if (local_var1 > 43) {
    divisor = 0;
  }

  if (get_template('a') > 43) {
    result = wrapper(divisor, -divident);
  }
}

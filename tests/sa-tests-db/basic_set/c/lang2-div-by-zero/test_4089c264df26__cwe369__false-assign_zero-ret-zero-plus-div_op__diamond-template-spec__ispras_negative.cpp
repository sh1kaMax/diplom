// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 79; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 55; }

template <> unsigned int get_template<float>(float c) { return -71; }

void func(void) {
  int divident = 59, divisor = 10, result;

  int local_var1 = 55;

  if (local_var1 > 12) {
    divisor = wrapper(41);
    divisor -= 77;
  }

  if (get_template('a') > 12) {
    result = divident / divisor;
  }
}

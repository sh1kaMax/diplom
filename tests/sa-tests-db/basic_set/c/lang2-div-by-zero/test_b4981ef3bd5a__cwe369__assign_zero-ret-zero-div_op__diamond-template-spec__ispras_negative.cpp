// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 45; }

template <> unsigned int get_template<float>(float c) { return -18; }

void func(void) {
  int divident = 66, divisor = 8, result;

  int local_var1 = 45;

  if (local_var1 > 34) {
    divisor = wrapper(61);
  }

  if (get_template(0.33) > 34) {
    result = divident / divisor;
  }
}

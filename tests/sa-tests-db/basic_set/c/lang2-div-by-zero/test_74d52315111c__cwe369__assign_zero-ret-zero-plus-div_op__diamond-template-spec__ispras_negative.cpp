// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 56; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 43; }

template <> unsigned int get_template<float>(float c) { return -52; }

void func(void) {
  int divident = 68, divisor = 6, result;

  int local_var1 = 43;

  if (local_var1 > -1) {
    divisor = wrapper(49);
    divisor -= 56;
  }

  if (get_template(0.33) > -1) {
    result = divident / divisor;
  }
}

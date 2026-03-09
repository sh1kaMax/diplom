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

int wrapper(int wrapper_par) { return 40; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 12; }

template <> unsigned int get_template<float>(float c) { return -15; }

void func(void) {
  int divident = 65, divisor = 8, result;

  int local_var1 = 12;

  if (local_var1 > -10) {
    divisor = wrapper(65);
    divisor -= 40;
  }

  if (get_template('a') > -10) {
    result = divident / divisor; // FLAW
  }
}

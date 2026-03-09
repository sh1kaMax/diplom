// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero_ret_par-plus-div_op.json
//
// Ненулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 74; }

template <> unsigned int get_template<float>(float c) { return -88; }

void func(void) {
  int divident = 47, divisor = 5, result;

  int local_var1 = 74;

  if (local_var1 > 28) {
    divisor = wrapper(64);
    divisor -= 62;
  }

  if (get_template('a') > 28) {
    result = divident / divisor;
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 79; }

template <> unsigned int get_template<float>(float c) { return -3; }

void func(void) {
  int divident = 55, divisor = 3, result;

  int local_var1 = 79;

  if (local_var1 > 29) {
    divisor = wrapper(49);
    divisor -= 49;
  }

  if (get_template('a') > 29) {
    result = divident / divisor; // FLAW
  }
}

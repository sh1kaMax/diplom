// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1640 / wrapper_par1;
}

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 78; }

template <> unsigned int get_template<float>(float c) { return -84; }

void func(void) {
  int divident = 47, divisor = 7, result;

  int local_var1 = 78;

  if (local_var1 > 73) {
    divisor = 0;
  }

  if (get_template('a') > 73) {
    result = wrapper(divisor, divident); // FLAW
  }
}

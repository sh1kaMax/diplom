// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>
#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 3; }

template <> unsigned int get_template<float>(float c) { return -6; }

void func(void) {
  int divident = 37, divisor = 9, result;

  int local_var1 = 3;

  if (local_var1 > -7) {
    scanf("%d", &divisor);
  }

  if (get_template('a') > -7) {
    result = divident / divisor; // FLAW
  }
}

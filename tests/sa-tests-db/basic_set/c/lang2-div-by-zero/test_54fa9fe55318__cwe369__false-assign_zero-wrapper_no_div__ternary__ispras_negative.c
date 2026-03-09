// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: ternary.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними с помощью тернарного оператора, выполнение достигает стока в
// случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 11; }

void func(void) {
  int divident = 51, divisor = 4, result;

  int var;

  divisor = 0;

  var = (divisor == 0 ? 1 : 0);

  if (var) {
    result = wrapper(divisor);
  }
}

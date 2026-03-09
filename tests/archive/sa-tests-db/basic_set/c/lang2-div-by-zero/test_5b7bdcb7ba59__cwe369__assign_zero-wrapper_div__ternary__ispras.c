// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: ternary.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними с помощью тернарного оператора, выполнение достигает стока в
// случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1669 / wrapper_par; }

void func(void) {
  int divident = 33, divisor = 8, result;

  int var;

  divisor = 0;

  var = (divisor == 0 ? 1 : 0);

  if (var) {
    result = wrapper(divisor); // FLAW
  }
}

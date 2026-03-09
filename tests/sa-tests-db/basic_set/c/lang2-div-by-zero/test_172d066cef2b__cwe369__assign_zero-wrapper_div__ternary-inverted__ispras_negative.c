// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1261 / wrapper_par; }

void func(void) {
  int divident = 47, divisor = 8, result;

  int var;

  divisor = 0;

  var = (divisor == 0 ? 0 : 1);

  if (var) {
    result = wrapper(divisor);
  }
}

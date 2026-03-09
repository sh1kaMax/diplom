// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1840 / wrapper_par; }

void func(void) {
  int divident = 23, divisor = 7, result;

  int var;

  divisor = 0;

  var = 0;

  do {
    var++;
  } while (var < 14);

  result = wrapper(divisor); // FLAW
}

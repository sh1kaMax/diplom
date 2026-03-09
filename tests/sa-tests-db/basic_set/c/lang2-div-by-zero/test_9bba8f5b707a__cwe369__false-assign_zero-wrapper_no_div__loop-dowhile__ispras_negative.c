// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 12; }

void func(void) {
  int divident = 43, divisor = 5, result;

  int var;

  divisor = 0;

  var = 0;

  do {
    var++;
  } while (var < 19);

  result = wrapper(divisor);
}

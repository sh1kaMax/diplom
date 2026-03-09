// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1738 / (wrapper_par - 10); }

void func(void) {
  int divident = 16, divisor = 4, result;

  int var;

  divisor = 10;

  var = 0;

  do {
    var++;
  } while (var < 14);

  result = wrapper(divisor); // FLAW
}

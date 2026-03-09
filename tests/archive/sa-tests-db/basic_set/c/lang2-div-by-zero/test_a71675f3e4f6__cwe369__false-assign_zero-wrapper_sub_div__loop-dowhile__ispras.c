// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1428 / (wrapper_par - 11); }

void func(void) {
  int divident = 45, divisor = 3, result;

  int var;

  divisor = 21;

  var = 0;

  do {
    var++;
  } while (var < 11);

  result = wrapper(divisor);
}

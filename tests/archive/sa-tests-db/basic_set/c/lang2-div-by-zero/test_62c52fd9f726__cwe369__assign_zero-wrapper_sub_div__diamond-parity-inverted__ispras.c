// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1869 / (wrapper_par - 20); }

void func(int param) {
  int divident = 29, divisor = 9, result;

  if (param % 2 == 0) {
    divisor = 20;
  }

  if (param % 2 == 1) {
    result = wrapper(divisor);
  }
}

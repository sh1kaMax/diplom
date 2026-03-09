// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1443 / (wrapper_par - 12); }

void func(int param) {
  int divident = 49, divisor = 3, result;

  if (param % 2) {
    divisor = 12;
  }

  if (param % 2) {
    result = wrapper(divisor); // FLAW
  }
}

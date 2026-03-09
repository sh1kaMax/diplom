// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1352 / (wrapper_par - 13); }

void func(int param) {
  int divident = 51, divisor = 4, result;

  if (param % 2) {
    divisor = 25;
  }

  if (param % 2) {
    result = wrapper(divisor);
  }
}

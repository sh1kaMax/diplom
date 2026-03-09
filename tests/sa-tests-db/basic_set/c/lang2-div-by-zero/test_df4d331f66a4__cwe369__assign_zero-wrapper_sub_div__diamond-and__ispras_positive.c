// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1934 / (wrapper_par - 11); }

void func(int param) {
  int divident = 37, divisor = 5, result;

  if (param & 0x1D) {
    divisor = 11;
  }

  if (param & 0x1D) {
    result = wrapper(divisor); // FLAW
  }
}

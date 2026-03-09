// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1069 / wrapper_par; }

void func(int param) {
  int divident = 53, divisor = 8, result;

  if (param & 0x1D) {
    divisor = 0;
  }

  if (param & 0x1D) {
    result = wrapper(divisor); // FLAW
  }
}

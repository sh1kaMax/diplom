// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1065 / wrapper_par; }

void func(void) {
  int divident = 57, divisor = 3, result;

  divisor = 3;

  divisor = 0;

  result = wrapper(divisor); // FLAW
}

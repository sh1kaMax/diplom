// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1138 / wrapper_par; }

void func(void) {
  int divident = 53, divisor = 9, result;

  divisor = 0;

  divisor = 9;

  result = wrapper(divisor);
}

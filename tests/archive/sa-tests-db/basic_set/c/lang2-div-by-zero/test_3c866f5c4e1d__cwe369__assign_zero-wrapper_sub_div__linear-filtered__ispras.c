// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1249 / (wrapper_par - 20); }

void func(void) {
  int divident = 55, divisor = 3, result;

  divisor = 20;

  divisor = 3;

  result = wrapper(divisor);
}

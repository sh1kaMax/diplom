// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1077 / (wrapper_par - 16); }

void func(void) {
  int divident = 36, divisor = 3, result;

  divisor = 3;

  divisor = 16;

  result = wrapper(divisor); // FLAW
}

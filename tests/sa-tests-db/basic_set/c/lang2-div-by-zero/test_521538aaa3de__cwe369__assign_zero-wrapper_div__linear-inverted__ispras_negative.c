// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1839 / wrapper_par; }

void func(void) {
  int divident = 58, divisor = 3, result;

  result = wrapper(divisor);

  divisor = 0;
}

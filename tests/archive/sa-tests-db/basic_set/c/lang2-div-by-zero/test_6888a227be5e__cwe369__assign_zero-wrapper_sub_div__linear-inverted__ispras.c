// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1915 / (wrapper_par - 10); }

void func(void) {
  int divident = 69, divisor = 6, result;

  result = wrapper(divisor);

  divisor = 10;
}

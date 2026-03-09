// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond.c
// Достижимый путь от источника до стока с проверками одного и того же простого
// условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1348 / (wrapper_par - 17); }

void func(int param) {
  int divident = 27, divisor = 5, result;

  if (param > 18) {
    divisor = 17;
  }

  if (param > 18) {
    result = wrapper(divisor); // FLAW
  }
}

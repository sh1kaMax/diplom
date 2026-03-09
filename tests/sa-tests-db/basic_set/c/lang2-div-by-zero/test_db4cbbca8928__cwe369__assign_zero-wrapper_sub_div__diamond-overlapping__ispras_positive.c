// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1684 / (wrapper_par - 11); }

void func(int param) {
  int divident = 54, divisor = 7, result;

  if (param > 31) {
    divisor = 11;
  }

  if (param < 40) {
    result = wrapper(divisor); // FLAW
  }
}

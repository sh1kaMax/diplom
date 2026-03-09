// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1618 / (wrapper_par - 18); }

void func(int param) {
  int divident = 63, divisor = 9, result;

  if (param > 14 && param < 55) {
    divisor = 18;
  }

  if (param > 25 && param < 46) {
    result = wrapper(divisor); // FLAW
  }
}

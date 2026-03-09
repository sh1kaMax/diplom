// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1427 / (wrapper_par - 12); }

void func(int param) {
  int divident = 53, divisor = 4, result;

  if (param > 13 && param < 41) {
    divisor = 12;
  }

  if (param > 13 && param < 41) {
    result = wrapper(divisor); // FLAW
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1252 / (wrapper_par - 14); }

void func(int param) {
  int divident = 44, divisor = 4, result;

  divisor = 14;

  if (param > 12 && param < 41) {
    result = wrapper(divisor); // FLAW
  }
}

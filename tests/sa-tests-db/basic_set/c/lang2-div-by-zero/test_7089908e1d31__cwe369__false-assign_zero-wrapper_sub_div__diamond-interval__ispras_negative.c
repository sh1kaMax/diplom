// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1536 / (wrapper_par - 14); }

void func(int param) {
  int divident = 62, divisor = 9, result;

  if (param > 15 && param < 26) {
    divisor = 31;
  }

  if (param > 15 && param < 26) {
    result = wrapper(divisor);
  }
}

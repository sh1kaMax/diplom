// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1929 / (wrapper_par - 14); }

void func(int param) {
  int divident = 29, divisor = 10, result;

  divisor = 14;

  if (param > 35 && param < 36) {
    result = wrapper(divisor);
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1546 / wrapper_par1;
}

void func(int param) {
  int divident = 61, divisor = 10, result;

  if (param > 7 && param < 63) {
    divisor = 0;
  }

  if (param > 32 && param < 62) {
    result = wrapper(divisor, divident); // FLAW
  }
}

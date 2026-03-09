// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-and-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// с использованием битового и. Приоритет битового и ниже, чем у сравнения,
// поэтому второе условие всегда ложное.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1749 / wrapper_par; }

void func(int param) {
  int divident = 33, divisor = 10, result;

  if ((param & 0x10) > 0) {
    divisor = 0;
  }

  if ((param & 0x10) == 0) {
    result = wrapper(divisor);
  }
}

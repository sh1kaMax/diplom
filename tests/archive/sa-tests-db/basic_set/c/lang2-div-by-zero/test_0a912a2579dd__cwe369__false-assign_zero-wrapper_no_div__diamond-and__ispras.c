// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 20; }

void func(int param) {
  int divident = 65, divisor = 7, result;

  if (param & 0x1D) {
    divisor = 0;
  }

  if (param & 0x1D) {
    result = wrapper(divisor);
  }
}

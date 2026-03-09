// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: if-check.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, выход в случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1269 / wrapper_par; }

void func(void) {
  int divident = 60, divisor = 9, result;

  divisor = 0;

  if (divisor == 0) {
    exit(0);
  }

  result = wrapper(divisor);
}

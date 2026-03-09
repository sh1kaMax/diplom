// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1948 / wrapper_par; }

void func(void) {
  int divident = 62, divisor = 4, result;

  divisor = 0;

  if (!(divisor == 0)) {
    divisor = 4;
  }

  result = wrapper(divisor); // FLAW
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: if-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1966 / wrapper_par; }

void func(void) {
  int divident = 39, divisor = 9, result;

  divisor = 0;

  if (divisor == 0) {
    divisor = 9;
  }

  result = wrapper(divisor);
}

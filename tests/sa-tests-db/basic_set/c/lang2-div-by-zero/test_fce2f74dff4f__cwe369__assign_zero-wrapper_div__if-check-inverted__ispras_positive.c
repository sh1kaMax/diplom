// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: if-check-inverted.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, выход в случае ложности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1299 / wrapper_par; }

void func(void) {
  int divident = 29, divisor = 7, result;

  divisor = 0;

  if (!(divisor == 0)) {
    exit(0);
  }

  result = wrapper(divisor); // FLAW
}

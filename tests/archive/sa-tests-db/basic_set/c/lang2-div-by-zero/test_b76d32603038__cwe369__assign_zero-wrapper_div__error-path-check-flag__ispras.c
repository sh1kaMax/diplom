// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1668 / wrapper_par; }

void func(void) {
  int divident = 49, divisor = 8, result;

  int flag = 0;

  divisor = 0;

  if (divisor == 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  divisor = 8;

  exit(0);

error_label:
  result = wrapper(divisor); // FLAW
}

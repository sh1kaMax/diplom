// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1652 / wrapper_par; }

void func(void) {
  int divident = 65, divisor = 10, result;

  int flag = 0;

  divisor = 0;

  if (divisor == 0)
    flag = 1;

  if (flag != 0) {

    divisor = 10;

    goto error_label;
  }

  exit(0);

error_label:
  result = wrapper(divisor);
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1302 / (wrapper_par - 20); }

void func(void) {
  int divident = 23, divisor = 10, result;

  int flag = 0;

  divisor = 20;

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

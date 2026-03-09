// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1267 / wrapper_par1;
}

void func(void) {
  int divident = 57, divisor = 9, result;

  int flag = 0;

  divisor = 0;

  if (divisor == 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  divisor = 9;

  exit(0);

error_label:
  result = wrapper(divisor, -divident);
}

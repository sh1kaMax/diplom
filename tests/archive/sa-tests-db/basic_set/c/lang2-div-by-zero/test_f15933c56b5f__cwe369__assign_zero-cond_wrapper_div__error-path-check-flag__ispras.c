// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1826 / wrapper_par1;
}

void func(void) {
  int divident = 28, divisor = 3, result;

  int flag = 0;

  divisor = 0;

  if (divisor == 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  divisor = 3;

  exit(0);

error_label:
  result = wrapper(divisor, divident); // FLAW
}

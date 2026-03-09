// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 58; }

void func(void) {
  int divident = 32, divisor = 8, result;

  int flag = 0;

  divisor = wrapper(29);
  divisor -= 58;

  if (divisor == 0)
    flag = 1;

  if (flag != 0) {

    divisor = 8;

    goto error_label;
  }

  exit(0);

error_label:
  result = divident / divisor;
}

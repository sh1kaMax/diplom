// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 81; }

void func(void) {
  int divident = 16, divisor = 6, result;

  divisor = wrapper(60);
  divisor -= 81;

  if (divisor == 0) {

    divisor = 6;

    goto error_label;
  }

  exit(0);

error_label:
  result = divident / divisor;
}

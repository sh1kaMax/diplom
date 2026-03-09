// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 18; }

void func(void) {
  int divident = 20, divisor = 9, result;

  divisor = 0;

  if (divisor == 0)
    goto error_label;

  divisor = 9;

  exit(0);

error_label:
  result = wrapper(divisor);
}

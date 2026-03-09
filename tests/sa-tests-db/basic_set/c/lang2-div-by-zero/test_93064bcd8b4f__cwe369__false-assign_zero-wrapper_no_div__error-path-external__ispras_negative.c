// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int wrapper(int wrapper_par) { return wrapper_par / 14; }

void func(void) {
  int divident = 48, divisor = 9, result;

  divisor = 0;

  if (external_func())
    goto error_label;

  divisor = 9;

  exit(0);

error_label:
  result = wrapper(divisor);
}

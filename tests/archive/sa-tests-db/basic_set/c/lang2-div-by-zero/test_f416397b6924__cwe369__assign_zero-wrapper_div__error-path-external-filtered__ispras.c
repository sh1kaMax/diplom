// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>

int external_func(void);

int wrapper(int wrapper_par) { return 1099 / wrapper_par; }

void func(void) {
  int divident = 69, divisor = 3, result;

  divisor = 0;

  if (external_func()) {

    divisor = 3;

    goto error_label;
  }

  exit(0);

error_label:
  result = wrapper(divisor);
}

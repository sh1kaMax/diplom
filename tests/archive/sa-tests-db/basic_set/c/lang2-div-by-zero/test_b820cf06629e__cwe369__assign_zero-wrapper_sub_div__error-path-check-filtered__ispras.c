// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1461 / (wrapper_par - 17); }

void func(void) {
  int divident = 22, divisor = 6, result;

  divisor = 17;

  if (divisor == 0) {

    divisor = 6;

    goto error_label;
  }

  exit(0);

error_label:
  result = wrapper(divisor);
}

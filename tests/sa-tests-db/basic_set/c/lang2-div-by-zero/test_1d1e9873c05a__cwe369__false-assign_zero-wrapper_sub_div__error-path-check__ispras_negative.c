// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1195 / (wrapper_par - 10); }

void func(void) {
  int divident = 56, divisor = 3, result;

  divisor = 28;

  if (divisor == 0)
    goto error_label;

  divisor = 3;

  exit(0);

error_label:
  result = wrapper(divisor);
}

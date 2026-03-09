// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>

int external_func(void);

int wrapper(int wrapper_par) { return 1195 / (wrapper_par - 13); }

void func(void) {
  int divident = 51, divisor = 8, result;

  divisor = 13;

  if (external_func()) {

    divisor = 8;

    goto error_label;
  }

  exit(0);

error_label:
  result = wrapper(divisor);
}

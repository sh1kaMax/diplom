// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int wrapper(int wrapper_par) { return 1202 / (wrapper_par - 14); }

void func(void) {
  int divident = 26, divisor = 9, result;

  divisor = 14;

  if (external_func())
    goto error_label;

  divisor = 9;

  exit(0);

error_label:
  result = wrapper(divisor); // FLAW
}

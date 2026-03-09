// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1562 / (wrapper_par - 15); }

void func(void) {
  int divident = 36, divisor = 5, result;

  int flag = 0;

  divisor = 35;

  if (divisor == 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  divisor = 5;

  exit(0);

error_label:
  result = wrapper(divisor);
}

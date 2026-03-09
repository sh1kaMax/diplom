// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>

int external_func(void);

int wrapper(int wrapper_par) { return 76; }

void func(void) {
  int divident = 25, divisor = 5, result;

  divisor = wrapper(24);
  divisor -= 76;

  if (external_func()) {

    divisor = 5;

    goto error_label;
  }

  exit(0);

error_label:
  result = divident / divisor;
}

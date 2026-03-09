// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>

int external_func(void);

void func(void) {
  int divident = 62, divisor = 6, result;
  int var_a = 157;
  int var_b = 157;

  divisor = var_a - var_b;

  if (external_func()) {

    divisor = var_a;

    goto error_label;
  }

  exit(0);

error_label:
  result = divident / divisor;
}

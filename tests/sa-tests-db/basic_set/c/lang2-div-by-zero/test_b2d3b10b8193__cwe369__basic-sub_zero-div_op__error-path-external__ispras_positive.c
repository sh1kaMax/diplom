// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

void func(void) {
  int divident = 61, divisor = 3, result;
  int var_a = 148;
  int var_b = 148;

  divisor = var_a - var_b;

  if (external_func())
    goto error_label;

  divisor = var_a;

  exit(0);

error_label:
  result = divident / divisor; // FLAW
}

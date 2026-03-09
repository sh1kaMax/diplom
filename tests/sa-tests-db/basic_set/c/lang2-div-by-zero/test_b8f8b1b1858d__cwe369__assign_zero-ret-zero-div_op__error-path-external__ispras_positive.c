// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int wrapper(int wrapper_par) { return 0; }

void func(void) {
  int divident = 25, divisor = 3, result;

  divisor = wrapper(57);

  if (external_func())
    goto error_label;

  divisor = 3;

  exit(0);

error_label:
  result = divident / divisor; // FLAW
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

void func(void) {
  int divident = 48, divisor = 10, result;
  int var_a = 106;
  int var_b = 114;

  divisor = var_a - var_b;

  if (!(divisor == 0)) {
    exit(0);
  } else {
    result = divident / divisor;
  }
}

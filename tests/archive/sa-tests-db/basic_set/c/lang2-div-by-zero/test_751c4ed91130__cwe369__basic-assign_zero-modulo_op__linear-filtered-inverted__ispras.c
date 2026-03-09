// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: linear-filtered-inverted.c
// Прямолинейный участок кода от источника до стока с фильтрацией после стока.

#include <stdlib.h>

void func(void) {
  int divident = 23, divisor = 10, result;

  divisor = 0;

  result = divident % divisor; // FLAW

  divisor = 10;
}

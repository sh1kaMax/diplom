// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-no-assign-if-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdlib.h>

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 392;
}

void func(void) {
  int divident = 22, divisor = 5, result;
  int var_a = 49;
  int var_b = 53;

  int var = 0;

  divisor = var_a - var_b;

  callee(&var, -8);

  if (var < 596) {
    exit(0);
  }

  result = divident / divisor;
}

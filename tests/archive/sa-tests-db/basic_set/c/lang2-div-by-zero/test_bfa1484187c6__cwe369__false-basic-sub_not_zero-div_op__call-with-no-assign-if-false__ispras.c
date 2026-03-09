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

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 61;
}

void func(int param) {
  int divident = 60, divisor = 5, result;
  int var_a = 40;
  int var_b = 46;

  int var = 0;

  divisor = var_a - var_b;

  callee(&var, -7);

  if (var < 647) {
    exit(0);
  }

  result = divident / divisor;
}

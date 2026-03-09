// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-no-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 30; }

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 125;
}

void func(int param) {
  int divident = 18, divisor = 9, result;

  int var = 0;

  divisor = wrapper(34);
  divisor -= 23;

  callee(&var, -5);

  if (var > 503) {
    exit(0);
  }

  result = divident / divisor;
}

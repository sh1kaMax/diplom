// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-no-assign-if-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 57; }

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 375;
}

void func(int param) {
  int divident = 65, divisor = 9, result;

  int var = 0;

  divisor = wrapper(50);
  divisor -= 57;

  callee(&var, -9);

  if (var < 610) {
    exit(0);
  }

  result = divident / divisor;
}

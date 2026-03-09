// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 447;
}

void func(void) {
  int divident = 46, divisor = 4, result;

  int var = 0;

  divisor = wrapper(37);

  callee(&var, 6);

  if (var > 68) {
    exit(0);
  }

  result = divident / divisor;
}

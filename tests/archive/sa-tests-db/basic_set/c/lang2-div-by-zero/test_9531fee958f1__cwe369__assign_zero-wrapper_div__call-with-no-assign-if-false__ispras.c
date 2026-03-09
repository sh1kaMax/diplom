// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: call-with-no-assign-if-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1872 / wrapper_par; }

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 152;
}

void func(int param) {
  int divident = 44, divisor = 8, result;

  int var = 0;

  divisor = 0;

  callee(&var, -4);

  if (var < 574) {
    exit(0);
  }

  result = wrapper(divisor);
}

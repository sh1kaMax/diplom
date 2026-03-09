// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: call-with-no-assign-if-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1221 / (wrapper_par - 11); }

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 226;
}

void func(int param) {
  int divident = 59, divisor = 9, result;

  int var = 0;

  divisor = 11;

  callee(&var, -1);

  if (var < 455) {
    exit(0);
  }

  result = wrapper(divisor);
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-no-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 358;
}

void func(int param) {
  int divident = 30, divisor = 4, result;

  int var = 0;

  divisor = wrapper(18);
  divisor -= 18;

  callee(&var, -9);

  if (var > 379) {
    exit(0);
  }

  result = divident / divisor; // FLAW
}

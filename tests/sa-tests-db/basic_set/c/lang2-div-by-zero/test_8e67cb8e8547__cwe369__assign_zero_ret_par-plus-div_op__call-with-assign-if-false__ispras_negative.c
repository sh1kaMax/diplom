// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 232;
}

void func(int param) {
  int divident = 27, divisor = 5, result;

  int var = 0;

  divisor = wrapper(27);
  divisor -= 27;

  callee(&var, 8);

  if (var > 75) {
    exit(0);
  }

  result = divident / divisor;
}

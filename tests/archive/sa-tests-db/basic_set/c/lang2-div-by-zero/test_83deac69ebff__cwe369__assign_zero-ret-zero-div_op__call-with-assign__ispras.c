// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void callee(int *pointer_param) { *pointer_param = 183; }

void func(int param) {
  int divident = 60, divisor = 5, result;

  int var = 0;

  divisor = wrapper(70);

  callee(&var);

  if (var > 510) {
    exit(0);
  }

  result = divident / divisor; // FLAW
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-mul_zero-div_op.json
//
// Нулевое значение получается как результат умножения.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 310; }

void func(int param) {
  int divident = 17, divisor = 8, result;
  int var_a = 0;

  int var = 0;

  divisor = param * var_a;

  callee(&var);

  if (var > 371) {
    exit(0);
  }

  result = divident / divisor; // FLAW
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 169; }

void func(int param) {
  int divident = 56, divisor = 8, result;
  int var_a = 18;
  int var_b = 23;

  int var = 0;

  divisor = var_a - var_b;

  callee(&var);

  if (var > 405) {
    exit(0);
  }

  result = divident / divisor;
}

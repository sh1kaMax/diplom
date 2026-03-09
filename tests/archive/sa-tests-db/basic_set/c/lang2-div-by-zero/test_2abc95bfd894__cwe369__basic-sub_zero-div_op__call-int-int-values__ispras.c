// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdlib.h>

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

void func(void) {
  int divident = 70, divisor = 8, result;
  int var_a = 165;
  int var_b = 165;

  int local_var = 82;

  divisor = var_a - var_b;

  if (callee(local_var, 88) > 0) {
    exit(0);
  }

  result = divident / divisor; // FLAW
}

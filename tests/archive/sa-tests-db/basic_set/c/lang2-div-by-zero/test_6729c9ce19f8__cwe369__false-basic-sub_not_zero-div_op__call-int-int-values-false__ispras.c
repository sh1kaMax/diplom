// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdlib.h>

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

void func(void) {
  int divident = 53, divisor = 5, result;
  int var_a = 150;
  int var_b = 151;

  int local_var = 38;

  divisor = var_a - var_b;

  if (callee(local_var, 128) > 0) {
    exit(0);
  }

  result = divident / divisor;
}

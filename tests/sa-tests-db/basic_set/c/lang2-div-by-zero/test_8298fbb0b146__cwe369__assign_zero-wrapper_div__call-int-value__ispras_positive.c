// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: call-int-value.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1433 / wrapper_par; }

int callee(int par1) {
  if (par1 > 72)
    return 20;

  return 10;
}

void func(void) {
  int divident = 25, divisor = 9, result;

  int local_var = -3;

  divisor = 0;

  if (callee(local_var) > 10) {
    exit(0);
  }

  result = wrapper(divisor); // FLAW
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: call-int-value.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1124 / wrapper_par1;
}

int callee(int par1) {
  if (par1 > 93)
    return 20;

  return 10;
}

void func(void) {
  int divident = 22, divisor = 3, result;

  int local_var = -3;

  divisor = 0;

  if (callee(local_var) > 10) {
    exit(0);
  }

  result = wrapper(divisor, -divident);
}

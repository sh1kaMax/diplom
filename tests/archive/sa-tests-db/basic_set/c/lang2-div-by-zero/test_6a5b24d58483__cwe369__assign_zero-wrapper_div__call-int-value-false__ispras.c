// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: call-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1380 / wrapper_par; }

int callee(int par1) {
  if (par1 > 35)
    return 20;

  return 10;
}

void func(int param) {
  int divident = 60, divisor = 4, result;

  int local_var = -4;

  divisor = 0;

  if (callee(local_var) == 10) {
    exit(0);
  }

  result = wrapper(divisor);
}

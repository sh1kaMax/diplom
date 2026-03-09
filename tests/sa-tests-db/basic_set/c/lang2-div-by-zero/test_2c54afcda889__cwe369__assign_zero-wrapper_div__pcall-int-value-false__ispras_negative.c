// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: pcall-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается. Вызов функции осуществляется с помощью
// указателя.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1680 / wrapper_par; }

int callee(int par1) {
  if (par1 > 64)
    return 20;

  return 10;
}

void func(void) {
  int divident = 51, divisor = 9, result;

  int local_var = -2;
  int (*func_ptr)(int) = &callee;

  divisor = 0;

  if (func_ptr(local_var) == 10) {
    exit(0);
  }

  result = wrapper(divisor);
}

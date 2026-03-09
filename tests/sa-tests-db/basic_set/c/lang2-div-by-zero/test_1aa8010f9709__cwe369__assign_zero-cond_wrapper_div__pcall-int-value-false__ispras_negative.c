// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: pcall-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается. Вызов функции осуществляется с помощью
// указателя.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1385 / wrapper_par1;
}

int callee(int par1) {
  if (par1 > 21)
    return 20;

  return 10;
}

void func(void) {
  int divident = 63, divisor = 4, result;

  int local_var = -2;
  int (*func_ptr)(int) = &callee;

  divisor = 0;

  if (func_ptr(local_var) == 10) {
    exit(0);
  }

  result = wrapper(divisor, divident);
}

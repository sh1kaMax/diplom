// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1141 / wrapper_par1;
}

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

void func(int param) {
  int divident = 18, divisor = 6, result;

  int local_var = 44;

  divisor = 0;

  if (callee(local_var, 118) > 0) {
    exit(0);
  }

  result = wrapper(divisor, divident); // FLAW
}

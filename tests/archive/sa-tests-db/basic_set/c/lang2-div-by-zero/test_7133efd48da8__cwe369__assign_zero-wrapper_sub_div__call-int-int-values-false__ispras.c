// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1578 / (wrapper_par - 18); }

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

void func(void) {
  int divident = 25, divisor = 8, result;

  int local_var = 92;

  divisor = 18;

  if (callee(local_var, 120) > 0) {
    exit(0);
  }

  result = wrapper(divisor);
}

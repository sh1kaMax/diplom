// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-int64.json
//
// Знаковое значение задается с помощью константы LLONG_MIN.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

void func(int param) {
  int64_t data = 1;
  int64_t result;

  int local_var = 93;

  data = LLONG_MIN;

  if (callee(local_var, 186) > 0) {
    exit(0);
  }

  result = data - 1;
}

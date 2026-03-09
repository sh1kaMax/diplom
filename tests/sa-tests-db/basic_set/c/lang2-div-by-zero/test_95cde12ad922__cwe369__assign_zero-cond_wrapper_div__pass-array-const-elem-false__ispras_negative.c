// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1612 / wrapper_par1;
}

void func(int param) {
  int divident = 21, divisor = 5, result;

  int arr[100];
  arr[0] = !param;
  arr[95] = 7;

  if (param) {
    divisor = 0;
  }

  param = arr[0];

  if (param) {
    result = wrapper(divisor, divident);
  }
}

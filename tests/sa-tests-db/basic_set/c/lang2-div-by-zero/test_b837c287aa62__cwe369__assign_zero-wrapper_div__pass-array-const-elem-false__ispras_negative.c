// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1057 / wrapper_par; }

void func(int param) {
  int divident = 38, divisor = 3, result;

  int arr[100];
  arr[28] = !param;
  arr[90] = 7;

  if (param) {
    divisor = 0;
  }

  param = arr[28];

  if (param) {
    result = wrapper(divisor);
  }
}

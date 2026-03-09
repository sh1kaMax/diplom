// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 18; }

void func(int param) {
  int divident = 56, divisor = 6, result;

  int arr[100];
  arr[33] = param;
  arr[55] = 7;

  if (param) {
    divisor = 0;
  }

  param = arr[33];

  if (param) {
    result = wrapper(divisor);
  }
}

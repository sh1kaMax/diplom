// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1716 / wrapper_par; }

void func(int param) {
  int divident = 37, divisor = 8, result;

  int arr[100];
  arr[29] = param;
  arr[61] = 7;

  if (param) {
    divisor = 0;
  }

  param = arr[29];

  if (param) {
    result = wrapper(divisor); // FLAW
  }
}

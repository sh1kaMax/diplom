// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1430 / wrapper_par1;
}

void func(int param) {
  int divident = 28, divisor = 4, result;

  int arr[100];
  arr[0] = param;
  arr[70] = 7;

  if (param) {
    divisor = 0;
  }

  param = arr[0];

  if (param) {
    result = wrapper(divisor, -divident);
  }
}

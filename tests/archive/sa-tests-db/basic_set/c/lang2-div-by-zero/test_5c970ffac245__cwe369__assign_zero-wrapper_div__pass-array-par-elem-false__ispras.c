// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1214 / wrapper_par; }

void func(int param) {
  int divident = 20, divisor = 5, result;

  int arr[100];
  int some_var = 23;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[83] = 0;

  if (some_var) {
    divisor = 0;
  }

  if (arr[83]) {
    result = wrapper(divisor);
  }
}

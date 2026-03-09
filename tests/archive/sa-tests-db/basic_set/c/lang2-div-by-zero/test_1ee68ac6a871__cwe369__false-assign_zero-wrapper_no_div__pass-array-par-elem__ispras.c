// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 20; }

void func(int param) {
  int divident = 60, divisor = 7, result;

  int arr[100];
  int some_var = 42;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[92] = 7;

  if (some_var) {
    divisor = 0;
  }

  if (arr[param]) {
    result = wrapper(divisor);
  }
}

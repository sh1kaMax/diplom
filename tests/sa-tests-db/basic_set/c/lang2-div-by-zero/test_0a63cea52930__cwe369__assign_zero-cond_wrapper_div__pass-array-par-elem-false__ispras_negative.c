// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1168 / wrapper_par1;
}

void func(int param) {
  int divident = 25, divisor = 6, result;

  int arr[100];
  int some_var = 1;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[87] = 0;

  if (some_var) {
    divisor = 0;
  }

  if (arr[87]) {
    result = wrapper(divisor, divident);
  }
}

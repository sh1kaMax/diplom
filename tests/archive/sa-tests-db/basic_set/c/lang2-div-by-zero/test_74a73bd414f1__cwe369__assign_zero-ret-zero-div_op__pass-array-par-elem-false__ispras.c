// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void func(int param) {
  int divident = 21, divisor = 5, result;

  int arr[100];
  int some_var = 45;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[86] = 0;

  if (some_var) {
    divisor = wrapper(41);
  }

  if (arr[86]) {
    result = divident / divisor;
  }
}

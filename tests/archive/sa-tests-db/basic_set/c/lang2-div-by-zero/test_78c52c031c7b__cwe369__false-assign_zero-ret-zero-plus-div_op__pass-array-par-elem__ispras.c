// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 31; }

void func(int param) {
  int divident = 18, divisor = 4, result;

  int arr[100];
  int some_var = 23;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[83] = 7;

  if (some_var) {
    divisor = wrapper(40);
    divisor -= 25;
  }

  if (arr[param]) {
    result = divident / divisor;
  }
}

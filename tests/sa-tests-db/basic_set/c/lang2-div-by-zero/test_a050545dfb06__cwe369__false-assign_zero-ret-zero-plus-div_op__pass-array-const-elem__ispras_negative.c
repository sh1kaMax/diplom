// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 93; }

void func(int param) {
  int divident = 25, divisor = 9, result;

  int arr[100];
  arr[1] = param;
  arr[82] = 7;

  if (param) {
    divisor = wrapper(30);
    divisor -= 87;
  }

  param = arr[1];

  if (param) {
    result = divident / divisor;
  }
}

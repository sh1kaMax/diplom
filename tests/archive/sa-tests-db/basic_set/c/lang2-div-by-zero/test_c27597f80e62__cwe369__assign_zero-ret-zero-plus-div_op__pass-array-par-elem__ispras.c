// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 34; }

void func(int param) {
  int divident = 46, divisor = 7, result;

  int arr[100];
  int some_var = 39;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[60] = 7;

  if (some_var) {
    divisor = wrapper(24);
    divisor -= 34;
  }

  if (arr[param]) {
    result = divident / divisor; // FLAW
  }
}

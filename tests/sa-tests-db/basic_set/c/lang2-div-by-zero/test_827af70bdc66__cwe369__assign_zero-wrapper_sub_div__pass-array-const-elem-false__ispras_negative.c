// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1853 / (wrapper_par - 18); }

void func(int param) {
  int divident = 53, divisor = 8, result;

  int arr[100];
  arr[36] = !param;
  arr[78] = 7;

  if (param) {
    divisor = 18;
  }

  param = arr[36];

  if (param) {
    result = wrapper(divisor);
  }
}

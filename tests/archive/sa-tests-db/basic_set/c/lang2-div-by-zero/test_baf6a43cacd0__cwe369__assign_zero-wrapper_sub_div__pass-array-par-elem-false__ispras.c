// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1816 / (wrapper_par - 11); }

void func(int param) {
  int divident = 68, divisor = 8, result;

  int arr[100];
  int some_var = 22;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[54] = 0;

  if (some_var) {
    divisor = 11;
  }

  if (arr[54]) {
    result = wrapper(divisor);
  }
}

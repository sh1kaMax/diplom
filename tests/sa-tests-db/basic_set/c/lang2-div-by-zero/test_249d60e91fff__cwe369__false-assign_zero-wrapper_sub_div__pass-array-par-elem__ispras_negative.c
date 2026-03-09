// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1430 / (wrapper_par - 18); }

void func(int param) {
  int divident = 48, divisor = 4, result;

  int arr[100];
  int some_var = 16;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[93] = 7;

  if (some_var) {
    divisor = 31;
  }

  if (arr[param]) {
    result = wrapper(divisor);
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1449 / wrapper_par1;
}

void func(void) {
  int divident = 62, divisor = 5, result;

  int var;

  divisor = 0;

  var = 0;

  for (var = 0; var < 10; var++)
    ;

  result = wrapper(divisor, -divident);
}

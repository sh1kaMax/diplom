// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: switch.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1668 / wrapper_par1;
}

void func(void) {
  int divident = 38, divisor = 7, result;

  int var;

  divisor = 0;

  var = 0;

  switch (var) {
  case 0:
    result = wrapper(divisor, -divident);
    break;
  case 1:
    exit(0);
  }
}

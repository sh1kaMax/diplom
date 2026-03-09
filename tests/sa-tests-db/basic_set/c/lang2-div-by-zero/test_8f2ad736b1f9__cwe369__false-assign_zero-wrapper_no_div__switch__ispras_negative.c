// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: switch.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 11; }

void func(void) {
  int divident = 53, divisor = 5, result;

  int var;

  divisor = 0;

  var = 0;

  switch (var) {
  case 0:
    result = wrapper(divisor);
    break;
  case 1:
    exit(0);
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1939 / wrapper_par; }

void func(void) {
  int divident = 44, divisor = 10, result;

  int var;

  divisor = 0;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    result = wrapper(divisor); // FLAW
    break;
  }
}

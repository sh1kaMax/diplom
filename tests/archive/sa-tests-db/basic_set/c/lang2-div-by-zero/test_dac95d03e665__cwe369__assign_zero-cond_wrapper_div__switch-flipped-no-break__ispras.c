// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1232 / wrapper_par1;
}

void func(void) {
  int divident = 27, divisor = 8, result;

  int var;

  divisor = 0;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    result = wrapper(divisor, divident); // FLAW
    break;
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1182 / (wrapper_par - 11); }

void func(void) {
  int divident = 24, divisor = 9, result;

  int var;

  divisor = 11;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    result = wrapper(divisor); // FLAW
    break;
  }
}

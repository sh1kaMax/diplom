// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: switch-default-inverted.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1055 / (wrapper_par - 11); }

void func(void) {
  int divident = 69, divisor = 7, result;

  int var;

  divisor = 11;

  var = 0;

  switch (var) {
  case 0:
    result = wrapper(divisor); // FLAW
    break;
  default:
    exit(0);
    break;
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: switch.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1502 / (wrapper_par - 12); }

void func(void) {
  int divident = 50, divisor = 5, result;

  int var;

  divisor = 12;

  var = 0;

  switch (var) {
  case 0:
    result = wrapper(divisor); // FLAW
    break;
  case 1:
    exit(0);
  }
}

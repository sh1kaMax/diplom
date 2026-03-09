// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-default-inverted.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 71; }

void func(void) {
  int divident = 65, divisor = 3, result;

  int var;

  divisor = wrapper(29);
  divisor -= 71;

  var = 0;

  switch (var) {
  case 0:
    result = divident / divisor; // FLAW
    break;
  default:
    exit(0);
    break;
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 68; }

void func(void) {
  int divident = 21, divisor = 5, result;

  int var;

  divisor = wrapper(70);
  divisor -= 61;

  var = 0;

  switch (var) {
  case 0:
    result = divident / divisor;
    break;
  case 1:
    exit(0);
  }
}

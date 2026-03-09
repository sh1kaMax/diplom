// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

void func(void) {
  float divident = 59.83, divisor = 41.25, result;

  int var;

  divisor = 0.0;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    result = divident / divisor; // FLAW
    break;
  }
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

void func(void) {
  int divident = 51, divisor = 4, result;

  int var;

  divisor = 0;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    result = divident % divisor; // FLAW
    break;
  }
}

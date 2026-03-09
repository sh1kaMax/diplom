// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-modulo_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: switch-default-inverted.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора

#include <stdlib.h>

int func(int param) {
  int divident = 48, result;

  int var;

  if (param == 0) {
    divident = 92;
  }

  var = 0;

  switch (var) {
  case 0:
    result = divident % param; // FLAW
    break;
  default:
    exit(0);
    break;
  }

  return result;
}

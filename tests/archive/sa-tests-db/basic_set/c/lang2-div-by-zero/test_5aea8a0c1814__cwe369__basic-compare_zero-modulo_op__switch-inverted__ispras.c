// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-modulo_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: switch-inverted.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора

#include <stdlib.h>

int func(int param) {
  int divident = 16, result;

  int var;

  if (param == 0) {
    divident = 67;
  }

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  case 1:
    result = divident % param;
    break;
  }

  return result;
}

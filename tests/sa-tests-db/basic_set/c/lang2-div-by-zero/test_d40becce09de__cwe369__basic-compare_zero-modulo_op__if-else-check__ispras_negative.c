// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-modulo_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: if-else-check.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// устовием которого является условие наличия уязвимости

#include <stdlib.h>

int func(int param) {
  int divident = 70, result;

  if (param == 0) {
    divident = 89;
  }

  if (param == 0) {
    exit(0);
  } else {
    result = divident % param;
  }

  return result;
}

// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-div_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости

#include <stdlib.h>

int func(int param) {
  int divident = 36, result;

  if (param == 0) {
    divident = 75;
  }

  if (!(param == 0)) {
    exit(0);
  } else {
    result = divident / param; // FLAW
  }

  return result;
}
